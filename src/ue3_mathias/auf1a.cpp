// Gruppe M. Husted, A. Malze, S. Kutscher
#include <iostream>
#include <string>

using namespace std;

void replace(string &input, char a, char b) {
    for (size_t i = 0; i < (input.length()); i++) {
        if (input[i] == a) input[i] = b;
    }
}

int main() {
    string inp;
    char a, b;

    cout << "Bitte gebe eine Zeichenkette ein: ";
    cin >> inp;
    cout << "Welches Zeichen soll ersetzt werden?: ";
    cin >> a;
    cout << "Durch was soll es ersetzt werden?: ";
    cin >> b;
    cout << "Der Eingabestring lautet: \"" << inp << "\" und wird jetzt verarbeitet...\n\n\n";
    replace(inp, a, b);
    cout << "Der Ausgabestring lautet: \"" << inp << "\"\n";
}