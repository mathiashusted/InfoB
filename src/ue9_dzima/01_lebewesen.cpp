/* Informatik B Sommer 2023
 * 09.06.2023
 * Katharina Klost
 */

// Kompilieren: g++ -std=c++14 -Wall -Wextra -Werror -pedantic  05_lebewesen.cpp
// -o lebewesen

#include <iostream>
// Anmerkung: In der Spezifikation wurden die Ausgaben, welche nur
// didaktische Zwecke haben nicht berücktsichtigt.
class Lebewesen {
protected: // die Attribute sind in allen Unterklassen zu sehen
  unsigned gewicht;
  unsigned alter;
  unsigned groesse;

public:
  /*
  Voraussetzung: Keine
  Ergebnis: Keins
  Effekt: Ein neues Lebewesen mit übergebenem Gewicht und übergebener Größe ist
  erzeugt
  */
  Lebewesen(unsigned gewicht, unsigned groesse) {
    this->alter = 0;
    this->gewicht = gewicht;
    this->groesse = groesse;
    std::cout << "Lebewesen wurde geboren" << std::endl;
  }

  /*
  Voraussetzung: Keine
  Ergebnis: Keins
  Effekt: Ein neues Lebewesen mit den Attributen des übergebenen Lebewesens ist
  erzeugt
  */
  Lebewesen(const Lebewesen &other) {
    this->alter = other.alter;
    this->groesse = other.groesse;
    this->gewicht = other.gewicht;
    std::cout << "Lebewesen mit Copy-Konstruktor geklont" << std::endl;
  }

  /*
  Voraussetzung: Keine
  Effekt: Das Lebewesen hat nun die gleichen Eigenschaften, wie das übergebene
  Lebewesen Ergebnis: Eine Referenz auf das Lebewesen ist geliefert
  */
  Lebewesen &operator=(const Lebewesen &other) {
    std::cout << "Copy-Assignment Lebewesen" << std::endl;
    if (this != &other) {
      this->gewicht = other.gewicht;
      this->alter = other.alter;
      this->groesse = other.groesse;
    }
    return *this;
  }

  /*
  Voraussetzung: Keine
  Ergebnis: Keins
  Effekt: Der Speicher ist freigegeben
  */
  virtual ~Lebewesen() { std::cout << "Delete Lebewesen" << std::endl; }

  /*
  Voraussetzung: Keine
  Ergebnis: Keins
  Effekt: Das gewicht des Lebewesens ist erhöht
  */
  void essen() {
    std::cout << "Lebewesen isst" << std::endl;
    this->gewicht++;
  }

  /*
  Voraussetzung: Keine
  Ergebnis: Keins
  Effekt: keiner
  */
  // Methode zu didaktischen Zwecken, virtualisiert, wird also von der
  // Unterklasse überschattet
  virtual void atmen() { std::cout << "Lebewesen atmet" << std::endl; }
};

class Mensch : public Lebewesen { // Mensch erbt von Lebewesen
  unsigned iq;

public:
  /*
  Voraussetzung: Keine
  Ergebnis: Keins
  Effekt: Ein neuer Mensch mit dem gegebenen Gewicht, der Größe und dem IQ ist
  erzeugt
  */
  // Mensch(..) ruft zunächst den Konstruktor von Lebewesen auf.
  Mensch(unsigned gewicht, unsigned groesse, unsigned iq)
      : Lebewesen(gewicht, groesse) {
    this->iq = iq;
    std::cout << "Mensch ist geboren" << std::endl;
  }

  /*
Voraussetzung: Keine
Ergebnis: Keins
Effekt: Ein neuer Mensch mit den Attributen des übergebenen Menschen ist erzeugt
*/
  // ruft zunächst den Konstruktor von Lebewesen auf
  Mensch(const Mensch &other) : Lebewesen(other.gewicht, other.groesse) {
    this->iq = other.iq;
    std::cout << "Mensch ist geklont" << std::endl;
  }

  /*
Voraussetzung: Keine
Effekt: Der Mensch hat nun die gleichen Eigenschaften, wie der übergebene Mensch
Ergebnis: Eine Referenz auf den Menschen ist geliefert
*/
  Mensch &operator=(const Mensch &other) {
    std::cout << "Copy-Assignment Mensch" << std::endl;
    if (this != &other) {
      Lebewesen::operator=(other);
      this->iq = other.iq;
    }
    return *this;
  }

  /*
  Voraussetzung: Keine
  Ergebnis: Keins
  Effekt: Der Speicher ist freigegeben
  */
  ~Mensch() {
    std::cout << "Delete Mensch" << std::endl;
    // danach wird der Destruktor der Oberklasse aufgerufen
  }

  /*
  Voraussetzung: Keine
  Ergebnis: Keins
  Effekt: keiner
  */
  // Methode zu didaktischen Zwecken
  void atmen() { std::cout << "Mensch Atmet Luft" << std::endl; }

  /*
 Voraussetzung: Keine
 Ergebnis: Keins
 Effekt: der iq ist um eins erhöht
 */
  // Methode zu didaktischen Zwecken
  void lernen() {
    std::cout << "Mensch lernt" << std::endl;
    this->iq++;
  }

  /*
Voraussetzung: Keine
Ergebnis: das Gewicht des Menschen ist geliefert
Effekt: keiner
*/
  unsigned wiegen() {
    std::cout << "Mensch wird gewogen" << std::endl;
    return this->gewicht;
  }

  /*
Voraussetzung: Keine
Ergebnis: Der iq des Menschen ist geliefert
Effekt: keiner
*/
  unsigned iq_test() {
    std::cout << "Mensch macht IQ-test" << std::endl;
    return this->iq;
  }
};

class Vogel : public Lebewesen {
  // Übung
};

int main() {
  Mensch m = Mensch(70, 170, 100);
  m.lernen();
  m.essen();
  m.atmen();

  Lebewesen *l = new Mensch(100, 180, 90);
  (*l).atmen();
  l->atmen();
  l->essen();
  delete l;
  l = nullptr;
  std::cout << std::endl;

  Lebewesen l2 = Lebewesen(70, 24);
  l2.atmen();
}