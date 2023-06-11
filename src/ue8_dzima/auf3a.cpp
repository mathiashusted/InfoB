/*
Code von gromdimon
11.06.2023
*/

//**********************************************************************************************
// AUFGABE 3a

// (a) Schreiben Sie mit Hilfe von Templates eine Klasse schluesselWertPaar, die
// ein Paar aus einen Schlüssel und einem Wert darstellt. Die Klasse hat die
// beiden Attribute schluessel und wert. Überladen Sie den < Operator, in dem
// Sie die Schlüssel der Paare vergleichen und schreiben Sie Methoden, die es
// erlauben den schluessel und den wert zu verändern.

#include <iostream>
#include <string>
using namespace std;

template <typename T, typename U> class schluesselWertPaar {
private:
  T schluessel;
  U wert;

public:
  /*
  Voraussetzung: Keine
  Effekt: Ein schluesselWertPaar Objekt mit Schlüssel schluessel und Wert wert
  ist erzeugt Ergebnis: Keins
  */
  schluesselWertPaar(T schluessel, U wert) {
    this->schluessel = schluessel;
    this->wert = wert;
  }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Der Schlüssel des schluesselWertPaar Objekts ist geliefert
  */
  T getSchluessel() const { return schluessel; }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Der Wert des schluesselWertPaar Objekts ist geliefert
  */
  U getWert() const { return wert; }
  /*
  Voraussetzung: Keine
  Effekt: Der Schlüssel des schluesselWertPaar Objekts ist auf schluessel
  gesetzt Ergebnis: Keins
  */
  void setSchluessel(T schluessel) { this->schluessel = schluessel; }
  /*
  Voraussetzung: Keine
  Effekt: Der Wert des schluesselWertPaar Objekts ist auf wert gesetzt
  Ergebnis: Keins
  */
  void setWert(U wert) { this->wert = wert; }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: true, wenn der Schlüssel des schluesselWertPaar Objekts kleiner als
  der Schlüssel des anderen schluesselWertPaar Objekts ist, sonst false
  */
  bool operator<(const schluesselWertPaar &other) const {
    return schluessel < other.schluessel;
  }
};

int main() {
  schluesselWertPaar<int, string> paar1(1, "Eins");
  schluesselWertPaar<int, string> paar2(2, "Zwei");
  schluesselWertPaar<int, string> paar3(3, "Drei");
  schluesselWertPaar<int, string> paar4(4, "Vier");

  cout << paar1.getSchluessel() << " " << paar1.getWert() << endl;
  cout << paar2.getSchluessel() << " " << paar2.getWert() << endl;
  cout << paar3.getSchluessel() << " " << paar3.getWert() << endl;
  cout << paar4.getSchluessel() << " " << paar4.getWert() << endl;

  paar1.setSchluessel(5);
  paar1.setWert("Fünf");

  cout << paar1.getSchluessel() << " " << paar1.getWert() << endl;

  if (paar1 < paar2) {
    cout << paar1.getSchluessel() << " ist kleiner als "
         << paar2.getSchluessel() << endl;
  } else {
    cout << paar1.getSchluessel() << " ist nicht kleiner als "
         << paar2.getSchluessel() << endl;
  }

  return 0;
}