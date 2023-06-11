/*
Code von gromdimon
11.06.2023
*/

//**********************************************************************************************
// AUFGABE 1

// In dieser Aufgabe finden Sie einige Merkregeln zum objektorientierten
// Programmieren in C++. Geben Sie funktionierende Code-Beispiele an, die
// zeigen, warum die Merkregeln sinnvoll sind und begründen Sie dies. (a)
// Attribute und Hilfsmethoden sollen als private deklariert sein. (b) Methoden,
// die public sind, sowie die Konstruktoren als auch der Destruktor sollen
// spezifiziert sein. (Hier müssen Sie keine Code-Beispiele angeben.) (c) Das
// Signalwort const soll immer dort benutzt werden, wo es sinnvoll ist. (d) Jede
// Klasse, die mit new eigenen Speicher alloziert, soll einen Destruktor, einen
// Copy-Konstruktor und einen Copy-Assignment-Operator implementieren. (e)
// Benutze Call-by-Reference in Verbindung mit const statt Call-by-Value, wenn
// das übergebene Objekt nicht verändert werden soll.

#include <iostream>
#include <string>
using namespace std;

// (a) Attribute und Hilfsmethoden sollen als private deklariert sein.
// (b) Methoden, die public sind, sowie die Konstruktoren als auch der
// Destruktor sollen spezifiziert
class Person {
private:
  string name;
  int alter;

public:
  /*
  Voraussetzung: Keine
  Effekt: Ein Person Objekt mit Name name und Alter alter ist erzeugt
  Ergebnis: Keins
  */
  Person(string name, int alter) {
    this->name = name;
    this->alter = alter;
  }
  /*
  Voraussetzung: Keine
  Effekt: Das Person Objekt ist gelöscht
  Ergebnis: Keins
  */
  // ~Person() {
  //     cout << "Person " << name << " wird gelöscht." << endl;
  //     delete this;   // Löscht das Objekt, ähnlich wie delete this->name
  // }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Der Name der Person ist geliefert
  */
  string getName() const { return name; }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Das Alter der Person ist geliefert
  */
  int getAlter() const { return alter; }
};

// (c) Das Signalwort const soll immer dort benutzt werden, wo es sinnvoll ist.
// (e) Benutze Call-by-Reference in Verbindung mit const statt Call-by-Value,
// wenn das übergebene Objekt nicht verändert werden soll.
void printPerson(const Person &p) {
  cout << "Name: " << p.getName() << ", Alter: " << p.getAlter() << endl;
}

// (d) Jede Klasse, die mit new eigenen Speicher alloziert, soll einen
// Destruktor, einen Copy-Konstruktor und einen Copy-Assignment-Operator
// implementieren.
class Person2 {
private:
  string name;
  int alter;

public:
  /*
  Voraussetzung: Keine
  Effekt: Ein Person Objekt mit Name name und Alter alter ist erzeugt
  Ergebnis: Keins
  */
  Person2(string name, int alter) {
    this->name = name;
    this->alter = alter;
  }
  /*
  Voraussetzung: Keine
  Effekt: Das Person Objekt ist gelöscht
  Ergebnis: Keins
  */
  // ~Person2() {
  //     cout << "Person " << name << " wird gelöscht." << endl;
  //     delete this;   // Löscht das Objekt, ähnlich wie delete this->name
  // }
  /*
  Voraussetzung: Keine
  Effekt: Ein Person Objekt ist erzeugt, werlches die gleichen Attribute wie der
  Eingabeparameter p besitzt Ergebnis: Keins
  */
  // Copy Constructor
  Person2(const Person2 &p) {
    this->name = p.name;
    this->alter = p.alter;
  }
  /*
  Voraussetzung: Keine
  Effekt: Das Person Objekt hat nun die gleichen Attribute wie der
  Eingabeparameter p Ergebnis: Eine Referenz auf das Person Objekt ist geliefert
  */
  // Copy Assignment Operator
  Person2 &operator=(const Person2 &p) {
    if (this != &p) {
      this->name = p.name;
      this->alter = p.alter;
    }
    return *this;
  }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Der Name der Person ist geliefert
  */
  string getName() { return name; }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Das Alter der Person ist geliefert
  */
  int getAlter() { return alter; }
};

int main() {
  // (a) Attribute und Hilfsmethoden sollen als private deklariert sein.
  // (b) Methoden, die public sind, sowie die Konstruktoren als auch der
  // Destruktor sollen spezifiziert
  Person p1("Max", 20);
  cout << "Name: " << p1.getName() << ", Alter: " << p1.getAlter() << endl;

  // (c) Das Signalwort const soll immer dort benutzt werden, wo es sinnvoll
  // ist. (e) Benutze Call-by-Reference in Verbindung mit const statt
  // Call-by-Value, wenn das übergebene Objekt nicht verändert werden soll.
  cout << "printing person: " << endl;
  printPerson(p1);

  // (d) Jede Klasse, die mit new eigenen Speicher alloziert, soll einen
  // Destruktor, einen Copy-Konstruktor und einen Copy-Assignment-Operator
  // implementieren.
  Person2 p2("Bob", 22);
  Person2 p3 = p2;
  Person2 p4("Alice", 24);
  p4 = p2;
  cout << "Printing same persons: " << endl;
  cout << "Name: " << p2.getName() << ", Alter: " << p2.getAlter() << endl;
  cout << "Name: " << p3.getName() << ", Alter: " << p3.getAlter() << endl;
  cout << "Name: " << p4.getName() << ", Alter: " << p4.getAlter() << endl;
  return 0;
}
