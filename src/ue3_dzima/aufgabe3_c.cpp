/*
Code von gromdimon
3.05.2023
*/

//**********************************************************************************************
// AUFGABE 3c

#include <iostream>
#include <vector>
using namespace std;

enum class Abteilung {
  IT,
  Vertrieb,
  Personal,
  Buchhaltung,
};

struct angestellter {
  std::string name;
  int personalnummer;
  Abteilung abteilung;
  double gehalt;
};

// Vor: Keine
// Erg: Angestellter
// Eff: Liest einen Angestellten ein, und gibt ihn aus
angestellter read_angestellter() {
  angestellter a;

  std::cout << "Name: ";
  std::getline(std::cin, a.name);

  std::cout << "Personalnummer: ";
  std::cin >> a.personalnummer;

  std::cout << "Abteilung (IT=0, Vertrieb=1, Personal=2, Buchhaltung=3): ";
  int abteilung;
  std::cin >> abteilung;
  a.abteilung = static_cast<Abteilung>(abteilung);

  std::cout << "Gehalt: ";
  std::cin >> a.gehalt;

  return a;
}

// Vor: Vector von Angestellten, Abteilung
// Erg: Vector von Angestellten
// Eff: Gibt einen Vector von Angestellten zurück, die in der Abteilung arbeiten
vector<angestellter> abteilung(const vector<angestellter> &angestelltenListe,
                               Abteilung abt) {
  vector<angestellter> abtAngestellte;
  for (const auto &angestellter : angestelltenListe) {
    if (angestellter.abteilung == abt) { // If the angestellter is in the abt
      abtAngestellte.push_back(angestellter);
    }
  }
  return abtAngestellte;
}

// Vor: Keine
// Erg: Keine
// Eff: Liest einen Angestellten ein, und gibt ihn aus
int main() {
  vector<angestellter> angestelltenListe;

  // Angestellte einlesen
  int anzahl;
  cout << "Wie viele Angestellte möchten Sie einlesen? ";
  cin >> anzahl;

  for (int i = 0; i < anzahl; i++) {
    angestelltenListe.push_back(read_angestellter());
  }

  // Nach Abteilung suchen
  int abt;
  cout << "Für welche Abteilung möchten Sie die Angestellten suchen (IT=0, "
          "Vertrieb=1, Personal=2, Buchhaltung=3)? ";
  cin >> abt;

  auto abtAngestellte =
      abteilung(angestelltenListe, static_cast<Abteilung>(abt));

  // Ausgabe
  cout << "\nAngestellte in Abteilung " << abt << ":\n";
  for (const auto &angestellter : abtAngestellte) {
    cout << angestellter.name
         << ", Personalnummer: " << angestellter.personalnummer
         << ", Gehalt: " << angestellter.gehalt << endl;
  }

  return 0;
}
