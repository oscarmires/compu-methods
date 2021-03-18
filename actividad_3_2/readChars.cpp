#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

void read(string path) {
    ifstream file;
    string line;
    file.open(path);
    if (file.fail()) {
        throw runtime_error("Cannot open file.");
    }
    while (getline(file, line)) {
        cout << line << endl;
    }
}

int main() {
    try {
        read("textSample.txt");
    } catch(const std::runtime_error &re) {
        std::cerr << re.what() << '\n';
    }
    return 0;
}
