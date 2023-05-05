// Gruppe M. Husted, A. Malze, S. Kutscher
#include <iostream>
#include <string>

using namespace std;

enum class Abteilung {
    Werkstatt,
    Lager,
    Buchhaltung,
    Verkauf
};

struct Angestellter {
    string name;
    int personalnummer;
    Abteilung abt;
    int gehalt;
};

int main() {

}