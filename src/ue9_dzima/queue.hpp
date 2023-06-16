/* Informatik B SoSe23
* Spezifikation des ADT Queue
* Namen:
* Tutorium:
*/

#pragma once

template <typename E>
class queue{
public:
  virtual ~queue(){};

  /*
  Voraussetzung: keine
  Effekt: Keiner
  Ergebnis: Wenn die Queue leer ist, ist true geliefert, sonst ist false geliefert
  */
  virtual bool is_empty() const = 0;

  /*
  Voraussetzung: Die Queue ist nicht leer
  Effekt: Das vorderste Element ist aus der Queue entfernt
  Ergebnis: Das vorderste Element ist zurückgegeben
  */
  virtual E dequeue() = 0;

  /*
  Voraussetzung: Die Queue ist nicht leer
  Effekt: Keiner
  Ergebnis: Das vorderste Element ist zurückgegeben
  */
  virtual E front() const = 0;

  /*
  Voraussetzung: Keine
  Effekt: Das übergebene Element ist hinten in die Queue eingefügt
  Ergebnis: Keins
  */
  virtual void enqueue(E x) = 0;
};
