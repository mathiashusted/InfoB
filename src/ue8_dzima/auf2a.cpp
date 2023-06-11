/*
Code von gromdimon
11.06.2023
*/

//**********************************************************************************************
// AUFGABE 2a

// (a) Implementieren Sie eine Klasse E-scooter. Die Klasse soll mindestens 3
// Attribute, 4 Methoden, einen Konstruktor und den Destruktor besitzen.
// Überladen Sie den <-Operator: eine E-Scooter ist kleiner als ein anderes,
// wenn er weniger PS hat. Geben Sie außerdem das Klassendiagramm an und
// spezifizieren Sie die Methoden, die Konstruktoren und den Destruktor. Testen
// Sie ihre Klasse ausführlich.

#include <iostream>
#include <string>
using namespace std;

class E_scooter {
private:
  string name;
  int ps;
  int reichweite;

public:
  /*
  Voraussetzung: Keine
  Effekt: Ein E_scooter Objekt mit Name name, PS ps und Reichweite reichweite
  ist erzeugt Ergebnis: Keins
  */
  E_scooter(string name, int ps, int reichweite) {
    this->name = name;
    this->ps = ps;
    this->reichweite = reichweite;
  }
  /*
  Voraussetzung: Keine
  Effekt: Das E_scooter Objekt ist gelöscht
  Ergebnis: Keins
  */
  ~E_scooter() {
    cout << "E_scooter " << name << " wird gelöscht." << endl;
    // delete this;
  }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Der Name des E_scooters ist geliefert
  */
  string getName() const { return name; }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Die PS des E_scooters ist geliefert
  */
  int getPs() const { return ps; }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Die Reichweite des E_scooters ist geliefert
  */
  int getReichweite() const { return reichweite; }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Keins
  */
  void print() const {
    cout << "E_scooter " << name << " hat " << ps
         << " PS und eine Reichweite von " << reichweite << " km." << endl;
  }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: true, wenn der E_scooter weniger PS hat als der Eingabeparameter a,
  sonst false
  */
  bool operator<(const E_scooter &a) const { return ps < a.ps; }
};

int main() {
  E_scooter a("a", 1, 1);
  E_scooter b("b", 2, 2);
  E_scooter c("c", 3, 3);
  E_scooter d("d", 4, 4);

  a.print();
  b.print();
  c.print();
  d.print();

  cout << "a < b: " << (a < b) << endl;
  cout << "b < c: " << (b < c) << endl;
  cout << "c < d: " << (c < d) << endl;
  cout << "d < a: " << (d < a) << endl;

  return 0;
}