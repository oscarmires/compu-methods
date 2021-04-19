#include "HTMLfile.hpp"

/*
    Ejemplo de cómo utilizar html
*/

int main() {
    HTMLfile html("miArchivo.html");
    html.insertSpan("hola", "variable");
    html.newLine();
    html.tab();
    html.insertSpan("hola", "variable");
    html.writeAndClose();
}
