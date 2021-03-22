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
public:
    Automata() {}

    void readText(string path) {
        // leer un código
    }

    void restart() {
        this->currentState = 0;
    }
};

int main() {
    RuleSet rules;
    try {
        rules.loadFromFile("DFAtable.txt");
    } catch(const runtime_error& re) {
        std::cerr << re.what() << '\n';
    }
    cout << rules.getRule('=', 18).toString() << endl;
    return 0;
}
