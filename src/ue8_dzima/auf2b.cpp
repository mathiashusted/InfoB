/*
Code von gromdimon
11.06.2023
*/

//**********************************************************************************************
// AUFGABE 2b

// (b) Implementieren Sie eine Klasse Kochfeld. Die Klasse soll mindestens 3
// Attribute, 4 Methoden, und die Großen vier besitzen. Geben Sie außerdem das
// Klassendiagramm an und spezifizieren Sie die Methoden, die Konstruktoren und
// den Destruktor. Testen Sie ihre Klasse ausführlich.

#include <iostream>
#include <string>
using namespace std;

class Kochfeld {
private:
  string name;
  int anzahlKochfelder;
  int leistung;

public:
  /*
  Voraussetzung: Keine
  Effekt: Ein Kochfeld Objekt mit Name name, Anzahl der Kochfelder
  anzahlKochfelder und Leistung leistung ist erzeugt Ergebnis: Keins
  */
  Kochfeld(string name, int anzahlKochfelder, int leistung) {
    this->name = name;
    this->anzahlKochfelder = anzahlKochfelder;
    this->leistung = leistung;
  }
  /*
  Voraussetzung: Keine
  Effekt: Das Kochfeld Objekt ist gelöscht
  Ergebnis: Keins
  */
  // ~Kochfeld() {
  //     cout << "Kochfeld " << name << " wird gelöscht." << endl;
  //     delete this;
  // }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Der Name des Kochfelds ist geliefert
  */
  string getName() const { return name; }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Die Anzahl der Kochfelder des Kochfelds ist geliefert
  */
  int getAnzahlKochfelder() const { return anzahlKochfelder; }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Die Leistung des Kochfelds ist geliefert
  */
  int getLeistung() const { return leistung; }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Die Leistung des Kochfelds ist auf leistung gesetzt
  */
  void setLeistung(int leistung) { this->leistung = leistung; }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Die Anzahl der Kochfelder des Kochfelds ist auf anzahlKochfelder
  gesetzt
  */
  void setAnzahlKochfelder(int anzahlKochfelder) {
    this->anzahlKochfelder = anzahlKochfelder;
  }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Der Name des Kochfelds ist auf name gesetzt
  */
  void setName(string name) { this->name = name; }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Das Kochfeld ist auf der Konsole ausgegeben
  */
  void print() const {
    cout << "Kochfeld " << name << " mit " << anzahlKochfelder
         << " Kochfeldern und Leistung " << leistung << " W" << endl;
  }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Das Kochfeld ist auf der Konsole ausgegeben
  */
  friend ostream &operator<<(ostream &os, const Kochfeld &kochfeld) {
    os << "Kochfeld " << kochfeld.name << " mit " << kochfeld.anzahlKochfelder
       << " Kochfeldern und Leistung " << kochfeld.leistung << " W" << endl;
    return os;
  }
};

int main() {
  Kochfeld kochfeld("Siemens", 4, 2000);
  kochfeld.print();
  cout << kochfeld << endl;
  kochfeld.setLeistung(3000);
  cout << kochfeld << endl;
  return 0;
}