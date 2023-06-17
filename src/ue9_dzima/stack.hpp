/* Informatik B - Sommersemester 2023
Vorlesung am 09.06.2023
Katharina Klost

Das Interface für den ADT Stack
*/


#pragma once

template <typename E, typename K>

//Gespeicherte Daten: Beliebige Daten
class stack{
public:
  /*
  Voraussetzung: keine
  Ergebnis: keins
  Effekt: Der Speicher des Objekts ist freigegeben
  */
  virtual ~stack(){};

  /*
  Voraussetzung: keine
  Ergebnis: true genau dann wenn, der Stack leer ist
  Effekt: Keiner
  */
  virtual bool is_empty() const = 0;

  /*
  Voraussetzung: keine
  Ergebnis: Anzahl der Elemente auf dem Stack
  Effekt: Keiner
  */
  virtual unsigned size() const = 0;

  /*
  Voraussetzung: keine
  Ergebnis: keins
  Effekt: x wurde auf den Stack gelegt
  */
  virtual void push(E x) = 0;

  /*
  Voraussetzung: Der Stack hat mindestens 1 Element
  Ergebnis: Das jüngste Element des Stacks
  Effekt: Das jüngste Element wurde vom Stack entfernt
  */
  virtual E pop() = 0;

  /*
  Voraussetzung: Der Stack hat mindestens 1 Element
  Ergebnis: Das jüngste Element des Stacks
  Effekt: keiner
  */
  virtual E top() const = 0;
};
