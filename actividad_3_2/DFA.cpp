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
        return "State: " + to_string(this->state) + ", Char: '" + this->character + "' -> " + to_string(this->next);
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
        "real", 
        "real", 
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
        string token = "";
        for (int i = 0; i < dato.length(); i++) {	
            r1 = rules.getRule(dato[i], currentState);
            if (r1.getNext() == 18) { // si llega a final del token
                cout << token << "\t\t\t\t" << this->stateNames[currentState] << endl;
                token = "";
                restart();
                r1 = rules.getRule(dato[i], currentState);
            }
            this->currentState = r1.getNext();
            if (currentState != 0) {  // si ya comenzó token (esto para ignorar espacios previos)
                token += dato[i];
            }
        }
        
        // si terminó como un punto aislado, marcar como error
        if (currentState == 2 && token == ".") currentState = 17;

        // imprimir último token
        cout << token << "\t\t\t\t" << this->stateNames[currentState] << endl;
        token = "";
        restart();
    }
    
    void lexerAritmetico(string archivo) {
        // leer un código

        ifstream ficheroEntrada;
        string dato;

        ficheroEntrada.open(archivo, ios::in);
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

    // Función para probar tokens individuales
    void readSingleToken(string token) {
        
        token += ' ';
        Rule currentRule;
        for (char c : token) {
            currentRule = rules.getRule(c, this->currentState);
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
    automata.lexerAritmetico("TextFile1.txt");
    return 0;
}
