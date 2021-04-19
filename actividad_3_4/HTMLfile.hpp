#include <iostream>
#include <fstream>
using namespace std;

class HTMLfile {
private:
    ofstream file;
    string  path,
            content;
public:
    HTMLfile(string path);
    void insertSpan(string token, string htmlClass);
    void newLine();
    void space();
    void tab();
    void writeAndClose();
};