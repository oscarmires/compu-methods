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
    bool print;
public:
    Rule() {}

    Rule(char character, int state, int next, bool print) {
        this->character = character;
        this->state = state;
        this->next = next;
        this->print = print;
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

    bool getPrint() {
        return this->print;
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

        /*
            leer cada caracter
        */

        file.close();
    }
    
    Rule getRule(char character, int currentState) {
        if (this->rules.find(character) != rules.end()) {
            // si la key existe
            return this->rules[character][currentState];
        } else {
            // si no existe, devolver regla error
            return Rule(character, currentState, 17, 1);
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
