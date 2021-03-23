#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;


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
        return "State: " + to_string(this->state) + ", Char: '" + this->character + "' -> " + to_string(this->next);;
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
            return Rule(character, currentState, 17);
        }
    }
};


class Automata {
private:
    RuleSet rules;
    int currentState;
    string stateNames[19] {
        "", 
        "entero", 
        "real", 
        "real", 
        "", 
        "", 
        "real", 
        "variable",
        "asignación",
        "suma",
        "resta",
        "multiplicación",
        "división",
        "potencia",
        "comentario",
        "abre paréntesis",
        "cierra paréntesis",
        "error",
        ""
    };
public:
    Automata() {
        this->currentState = 0;
    }

    void loadRules(string path) {
        try {
            this->rules.loadFromFile(path);
        } catch(const runtime_error& re) {
            throw re;
        }
    }

    void AnalisisCaracteres(string dato)
    {
        Rule r1;
        for (int i = 0; i < dato.length()-1; i++)
        {	
            r1 = rules.getRule(dato[i], currentState);
            if (r1.getNext() == 18) {
                cout << "\t\t\t\t" << this->stateNames[currentState] << endl;
                restart();
                r1 = rules.getRule(dato[i], currentState);
            }
            this->currentState = r1.getNext();
            if (currentState != 0) { 
                cout << dato[i];
            }
        }
        cout << dato[dato.length()-1] << "\t\t\t\t" << this->stateNames[currentState] << endl;
        restart();
    }
    
    void readText(string path) {
        // leer un código

        ifstream ficheroEntrada;
        string dato;

        ficheroEntrada.open(path, ios::in);
        if (ficheroEntrada.is_open()) {
            while (!ficheroEntrada.eof())
            {

                stringstream ss(dato);

                while (getline(ficheroEntrada, dato))
                {
                        //cout << "nuevo ciclo" << endl;
                        AnalisisCaracteres(dato.c_str());

                }
                cout << endl;
            }
            ficheroEntrada.close();
        }
        else cout << "Fichero inexistente" << endl;
    }

    void readSingleToken(string token) {
        token += ' ';
        Rule currentRule;
        for (char c : token) {
            currentRule = rules.getRule(c, this->currentState);
            // cout << currentRule.toString() << endl;
            if (currentRule.getNext() == 17) {
                cout << token << "\t\terror" << endl;
                this->restart();
                return;
            } else if (currentRule.getNext() == 18) {
                cout << token << "\t\t" << stateNames[currentState] << endl;
                this->restart();
                return;
            } else {
                this->currentState = currentRule.getNext();
            }
        }
        cout << token << "\t\t" << stateNames[currentState] << endl;
        this->restart();
    }

    void restart() {
        this->currentState = 0;
    }
};

int main() {

    Automata automata;
    automata.loadRules("DFAtable.csv");
    automata.readText("TextFile1.txt");

/*
    automata.readSingleToken("");
    automata.readSingleToken("a");
    automata.readSingleToken("abc_12");
    automata.readSingleToken("abc12_");
    automata.readSingleToken("1");
    automata.readSingleToken("9999");
    automata.readSingleToken("2.");
    automata.readSingleToken("2.1");
    automata.readSingleToken(".12");
    automata.readSingleToken("-10");
    automata.readSingleToken("+");
    automata.readSingleToken("-");
    automata.readSingleToken("*");
    automata.readSingleToken("/");
    automata.readSingleToken("^");
    automata.readSingleToken("=");
    automata.readSingleToken("(");
    automata.readSingleToken(")");
    automata.readSingleToken("1.1e");
    automata.readSingleToken("1.1e7");
    automata.readSingleToken("1.1E7");
    automata.readSingleToken("1.1E-7");
    automata.readSingleToken("1.1e+7");
    automata.readSingleToken("-1.1e7");
    automata.readSingleToken("// abc");
    automata.readSingleToken("{");
    automata.readSingleToken(".");
*/

    return 0;
}
