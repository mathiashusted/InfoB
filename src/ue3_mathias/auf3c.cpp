// Gruppe M. Husted, A. Malze, S. Kutscher
#include <iostream>
#include <string>
#include <vector>

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
    Abteilung abteilung;
    int gehalt;
};

// Vor: Keine
// Erg: Liefert neue Instanz von Angestellter
Angestellter newAngesteller() {
    Angestellter mitarbeiter;
    string name;
    int personalnummer;
    string abt;
    int gehalt;
    cout << "Bitte gebe den Namen des Angestellten ein: ";
    cin >> name;
    mitarbeiter.name = name;
    cout << "Bitte gebe die Personalnummer des Angestellten ein: ";
    cin >> personalnummer;
    mitarbeiter.personalnummer = personalnummer;
    cout << "Bitte gebe die Abteilung des Angestellten ein: ";
    cin >> abt;
    // Je nachdem, was wir eingegeben haben, müssen wir es dem Eintrag aus dem enum Abteilung zuweisen:
    if      (abt == "Werkstatt")   mitarbeiter.abteilung = Abteilung::Werkstatt;
    else if (abt == "Lager")       mitarbeiter.abteilung = Abteilung::Lager;
    else if (abt == "Buchhaltung") mitarbeiter.abteilung = Abteilung::Buchhaltung;
    else if (abt == "Verkauf")     mitarbeiter.abteilung = Abteilung::Verkauf;
    cout << "Bitte gebe das Gehalt des Angestellten ein: ";
    cin >> gehalt;
    cout << "\n\n\n";
    return mitarbeiter;
}

// Vor: Keine
// Erg: Alle Angestellten des Inputs, die in der Abteilung abt arbeiten, werden in einem neuen Vektor ausgegeben.
vector<Angestellter> abteilung(vector<Angestellter> input, Abteilung abt) {
    vector<Angestellter> output; // Ausgabevektor
    for (size_t i = 0; i < (input.size()); i++) {
        if (input[i].abteilung == abt) output.push_back(input[i]); // Mitarbeiter wird zum Ausgabevektor hinzugefügt
    }
    return output;
}

int main() {
    Angestellter markus = newAngesteller();
    Angestellter sarah = newAngesteller();
    Angestellter manfred = newAngesteller();

    vector<Angestellter> all = {markus, sarah, manfred}; // Beispiel zu Verwendung der Funktion.
    cout << "Folgende Mitarbeiter arbeiten in der Werkstatt:\n";
    vector<Angestellter> inWerkstatt = abteilung(all, Abteilung::Werkstatt);
    for (size_t i = 0; i < inWerkstatt.size(); i++) {
        cout << inWerkstatt[i].name << endl; // Alle Mitarbeiter der Werkstatt werden aufgelistet
    }
}