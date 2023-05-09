// Gruppe M. Husted, A. Malze, S. Kutscher
#include <iostream>
#include <string>

using namespace std;


// Vor: Keine
// Erg: Keins
// Eff: Der Character a im String Input wird durch den Character b ersetzt
void replace(string &input, char a, char b) {
    for (size_t i = 0; i < (input.length()); i++) {
        if (input[i] == a) input[i] = b; // Buchstabe wird ersetzt
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
    replace(inp, a, b); // Funktion wird ausgeführt (da inp über einen Pointer verarbeitet wird, brauchen wir keine neue Variable)
    cout << "Der Ausgabestring lautet: \"" << inp << "\"\n";
}