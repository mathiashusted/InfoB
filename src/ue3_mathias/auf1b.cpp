// Gruppe M. Husted, A. Malze, S. Kutscher
#include <iostream>
#include <string>

using namespace std;

void strToUpper(string &input) {
    for (size_t i = 0; i < (input.length()); i++) {
        input[i] = static_cast<char>(toupper(input[i]));
    }
}

int main() {
    string inp;
    cout << "Bitte gebe eine Zeichenkette ein: ";
    cin >> inp;
    strToUpper(inp);
    cout << "Die Ausgabe beträgt: " << inp << endl;
}