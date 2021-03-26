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




int main() {

    return 0;
}
