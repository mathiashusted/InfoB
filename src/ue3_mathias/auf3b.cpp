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
    return mitarbeiter;
}

int main() {
    Angestellter markus = newAngesteller();
    cout << "Der Name des Angestellten lautet: " << markus.name
         << "\nDie Personalnummer des Angestellten lautet: " << markus.personalnummer
         << "\nDie Abteilung des Angestellten lautet: ";
    
    switch (markus.abteilung) { // Müssen wieder dem enum die Ausgaben zuweisen
        case (Abteilung::Buchhaltung):
            cout << "Buchhaltung";
            break;
        case (Abteilung::Lager):
            cout << "Lager";
            break;
        case (Abteilung::Verkauf):
            cout << "Verkauf";
            break;
        case (Abteilung::Werkstatt):
            cout << "Werkstatt";
            break;
        default:
            cout << "Nicht gefunden";
            break;
    }

    cout << "\nDas Gehalt des Angestellten lautet: " << markus.gehalt << endl;
}