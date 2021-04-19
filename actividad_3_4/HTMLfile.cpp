#ifndef HTMLFILE_HPP
#define HTMLFILE_HPP
#include "HTMLfile.hpp"
#include <stdexcept>

HTMLfile::HTMLfile(string path) {
    // Analyse file extension
    string fileExtension = "";
    for (int i = path.size() - 5; i < path.size(); i++) fileExtension += path[i];
    if (fileExtension != ".html") throw runtime_error("Wrong file extension. Use '.html' to create file.");
    // Create file
    file.open(path, ofstream::out | ofstream::trunc);
    if (file.fail()) throw runtime_error("Cannot read file");
}

void HTMLfile::insertSpan(string token, string htmlClass) {
    content +=  "<span class='"
                + htmlClass
                + "'>"
                + token
                + "</span>";
}

void HTMLfile::newLine() {
    content += "<br>";
}

void HTMLfile::tab() {
    content += "&nbsp;&nbsp;&nbsp;&nbsp;";
}

void HTMLfile::writeAndClose() { 
    file    << "<div id='export-code'>"
            << content
            << "</div>";
    file.close();
}

#endif
