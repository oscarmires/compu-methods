#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Rule {
	private:
		int state;
		char character;
		int next;
		bool print;
	public:
		Rule() {
			this->state = 0;
			this->next = 0;
			this->print = false;
		}

		Rule(int state, int next, bool print) {
			this->state = state;
			this->next = next;
			this->print = print;
		}
		
		int getNext() {
			return this->next;
		}

		bool getPrint() {
			return this->print;
		}

		bool isApplicable(int state, char character) {
			return state == this->state && character == this->character;
		}

		string toString() {
			return "State: " + to_string(this->state) + ", Char: " + this->character + " -> " + to_string(this->next);
		}
};

class RuleSet {
	private:
		vector<Rule> lettersRules;
		vector<Rule> numDigitsRules;
		vector<Rule> otherRules;
		vector<Rule> sumRules;
		vector<Rule> subtrRules;
		vector<Rule> multipRules;
		vector<Rule> slashRules;
		vector<Rule> powerRules;
		vector<Rule> openParenthesisRules;
		vector<Rule> closeParenthesisRules;
		vector<Rule> dotRules;
		vector<Rule> underscoreRules;
		vector<Rule> eRules;
		vector<Rule> spaceRules;
		vector<Rule> negativeNumRules;
		vector<Rule> equalSignRules;
	public: 
		RuleSet() {
			lettersRules.push_back(Rule(0, 5, 0));
		}
		void loadFromFile(string path) {

		}
		Rule getRule(int ascii, int currentState) {
			if (65 <= ascii && ascii <= 90 || 97 <= ascii && ascii <= 122) {
				return lettersRules[currentState];
			}
		}
};

class Automata {
	private:
		int estadoActual;
		RuleSet rules;
		vector<string> stateNames;
	public:
		Automata();
		void readFile(string path) {
			ifstream file;
			string line;
			Rule currentRule;
			file.open(path);
			if (file.fail()) {
				throw runtime_error("Cannot open file.");
			}
			while (getline(file, line)) {
				for (char c : line) {
					currentRule = rules.getRule((int) c, estadoActual);
					this->estadoActual = currentRule.getNext();
					if (currentRule.getPrint()) {
						cout << stateNames[estadoActual] << endl;
					}

				}
			}
			
		}
};

int main() {
	char c = 'a';
	int ascii = (int) c;
	cout << ascii << endl;
	
	return 0;
}
