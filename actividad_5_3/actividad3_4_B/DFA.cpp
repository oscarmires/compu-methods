#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <ctime>
using namespace std;

class Debugger {
private:
    ofstream debugOutput;
    bool opened;
public:
    Debugger() {
        this->debugOutput.open("html_output/debug-output.txt");
        if (debugOutput.fail()) {
            cout << "Debug file cannot open" << endl;
            this->opened = false;
        } else {
            this->opened = true;
        }
    }

    void write(string text) {
        if (this->opened) {
            this->debugOutput << text << endl;
        }
    }

    void close() {
        this->debugOutput.close();
    }
};


class Rule {
private:
    char character;
    int state, 
        next;
public:
    Rule() {}

    Rule(char character, int state, int next) {
        this->character = character;
        this->state = state;
        this->next = next;
    }

    char getCharacter() {
        return this->character;
    }

    int getState() {
        return this->state;
    }

    int getNext() {
        return this->next;
    }

    string toString() {
        return "State: " + to_string(this->state) + ", Char: '" + this->character + "' -> " + to_string(this->next);
    }
};


class RuleSet {
private:
    unordered_map<char, vector<Rule>> rules;
public:
    RuleSet() {}

    void loadFromFile(string path) {
        ifstream file;
        string line, cell, print;
        stringstream ss;
        vector<char> chars;
        
        file.open(path);
        if (file.fail()) {
            throw runtime_error("Cannot read file");
        }

        // leer encabezado (caracteres)
        getline(file, line);
        getline(file, line);
        ss << line;
        while (getline(ss, cell, ',')) {
            chars.push_back(cell[0]);
        }
        ss.str(string());
        ss.clear();

        // leer cuerpo de tabla (reglas)
        int stateNum = 0;
        while (getline(file, line)) {
            ss << line;
            for (int i = 0; i < chars.size(); i++) {
                getline(ss, cell, ',');
                this->rules[chars[i]].push_back(Rule(chars[i], stateNum, stoi(cell) ));
            }

            stateNum++;

            ss.str(string());
            ss.clear();
        }

        file.close();
    }
        
    Rule getRule(char character, int currentState) {
        if (this->rules.find(character) != rules.end()) {
            // si la key existe
            return this->rules[character][currentState];
        } else {
            // si no existe, devolver regla error
            if (currentState == 14) {
                return Rule(character, currentState, 14);
            }
            return Rule(character, currentState, 17);
        }
    }
};


class Automata {
private:
    RuleSet rules;
    int currentState;
    string exportFileName = "highlighted";
    string stateNames[23] {
        "",
        "integer", 
        "real", 
        "real", 
        "real", 
        "real", 
        "real", 
        "variable",
        "assignment",
        "addition",
        "subtraction",
        "multiplication",
        "division",
        "power",
        "comment",
        "open-parenthesis",
        "close-parenthesis",
        "error",
        "",
        "symbol",
        "",
        "true",
        "false"
    };
    string reservedKeywords[1] {"define"};
    Debugger* debugger;
public:
    Automata(Debugger* d) {
        this->currentState = 0;
        this->debugger = d;
    }

    void loadRules(string path) {
        try {
            this->rules.loadFromFile(path);
        } catch(const runtime_error& re) {
            throw re;
        }
    }

    bool isReservedKeyword(string token) {
        /*
            Complejidad
            Mejor caso: O(1)
            Peor caso: O(n)
        */


        // evalúa si la palabra que recibe es reservada
        for (string keyword : this->reservedKeywords) {
            if (token == keyword) return true;
        }
        return false;
    }


    //escribe HTML 
    vector<string> tokens;
    vector<string> estados;
    bool html =false;
   
    void writeHtml(string token, string estado){

        /*
            Complejidad
            Mejor caso: O(1)
            Peor caso: O(n)
        */

         tokens.push_back(token);
         estados.push_back(estado);

        if(html){
            ofstream fichero("html_output/" + this->exportFileName);            

            for(int i = 0; i!=tokens.size()-1; i++){
                if(i ==0){
                    if (estados[i] == "break") {
                        fichero  <<"<!DOCTYPE html>" <<'\n'<<"<html>"<<'\n'<<'\t'<<"<title>Tokens</title>"<<'\n'<<'\t'<<"<link rel='stylesheet' href='../styles.css'>"<< '\n' <<'\t' << "<body>"<< '\n'
                    <<'\t' <<'\t' << "<br>";
                    } else {
                        fichero  <<"<!DOCTYPE html>" <<'\n'<<"<html>"<<'\n'<<'\t'<<"<title>Tokens</title>"<<'\n'<<'\t'<<"<link rel='stylesheet' href='../styles.css'>"<< '\n' <<'\t' << "<body>"<< '\n'
                    <<'\t' <<'\t' <<"<div class='" <<estados[i]<<"'>"<< '\n'<<'\t' <<'\t' <<'\t' <<"<span>"<<tokens[i]<<"</span>"<< '\n' <<'\t' <<'\t' <<"</div> "<< '\n' ;
                    }
                }
                else if(i==tokens.size()-2){
                    if (estados[i] == "break") {
                        fichero   <<'\t' <<'\t' << "<br>";
                    } else {
                        fichero   <<'\t' <<'\t' <<"<div class='" <<estados[i]<<"'>"<< '\n'<<'\t' <<'\t' <<'\t' <<"<span>"<<tokens[i]<<"</span>"<< '\n' <<'\t' <<'\t' <<"</div> "<< '\n' 
                    << '\n' <<'\t' << "<body>" << '\n' << "</html>";
                    }
                }
                else{
                    if (estados[i] == "break") {
                        fichero   << "<br>" << '\n' <<'\t' <<'\t' <<"</div> "<< '\n' ;

                    } else {
                        fichero   <<'\t' <<'\t' <<"<div class='" <<estados[i]<<"'>"<< '\n'<<'\t' <<'\t' <<'\t' <<"<span>"<<tokens[i]<<"</span>"<< '\n' <<'\t' <<'\t' <<"</div> "<< '\n' ;
                    }
                }
           
            }
       
            fichero.close();  

        }

     
      
    }
   

    void exportToken(string &token) {
        /*
            Se utiliza al final de un token o al final de una línea
            para imprimir el token y guardarlo en un html
        */

        // si terminó como un punto aislado, marcar como error
        if (currentState == 2 && token == ".") currentState = 17;

        if (isReservedKeyword(token)) {
            cout << token << "\t\t\t\t" << "reserved-keyword" << endl;
            writeHtml(token,"reserved-keyword");
        } else {
            cout << token << "\t\t\t\t" << this->stateNames[currentState] << endl;
              writeHtml(token, this->stateNames[currentState]);
        }
        token = "";
        restart();
    }

    void AnalisisCaracteres(string dato)
    {
        /*
            Complejidad
            Mejor caso: O(1)
            Peor caso: O(n)
        */

        debugger->write(dato);

        Rule r1;
        string token = "";
        for (int i = 0; i < dato.length(); i++) {	
            r1 = rules.getRule(dato[i], currentState);
            if (r1.getNext() == 18) { // si llega a final del token
                exportToken(token);
                r1 = rules.getRule(dato[i], currentState);
            }
            this->currentState = r1.getNext();
            if (currentState != 0) {  // si ya comenzó token (esto para ignorar espacios previos)
                token += dato[i];
            } else {
                writeHtml("&nbsp;", "space");
            }
        }
        
        // imprimir último token
        exportToken(token);
        writeHtml("", "break");
    }
    
    void lexerAritmetico(string archivo) {
        /*
            Complejidad
            Mejor caso: O(1)
            Peor caso: O(n^2)
        */

        // leer un código

        debugger->write("Entered function lexerAritmetico.");

        this->exportFileName = "highlighted-" + archivo + ".html";

        ifstream ficheroEntrada;
        string dato;

        string fileToOpen = "scripts/" + archivo + ".txt";
        ficheroEntrada.open(fileToOpen, ios::in);

        debugger->write("Opened input script file.");

        if (ficheroEntrada.is_open()) {
                stringstream ss(dato);

                while (getline(ficheroEntrada, dato))
                {
                        //cout << "nuevo ciclo" << endl;
                        AnalisisCaracteres(dato.c_str());

                }
                cout << endl;
            ficheroEntrada.close();

            debugger->write("Closed input script file.");

            html = true;
            writeHtml("token", "final");
        }
        else cout << "Fichero inexistente" << endl;
    }

    void restart() {
        this->currentState = 0;
    }
};

int main(int argc, char const *argv[]) {

    Debugger* debugger = new Debugger;
    debugger->write("Begin execution.");

    unsigned t0, t1;
    t0 = clock();

    debugger->write("C++ clock initialized.");

    Automata automata(debugger);
    automata.loadRules("DFAtable.csv");

    debugger->write("Transitions load complete.");

    automata.lexerAritmetico(argv[2]);

    debugger->write("function lexerAritmetico finalized.");
    debugger->close();

    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << "s" << endl;
    return 0;
}
