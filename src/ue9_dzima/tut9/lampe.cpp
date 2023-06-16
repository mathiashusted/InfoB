/* Informatik B - Sommersemester 2023

Die Klasse Lampe
*/


#include <iostream>

class Lampe{
private:
  unsigned wattzahl;
  bool eingeschaltet;
  float lichtstaerke;
  bool kaputt;

public:
  void wechseln(unsigned wattzahl){
    this-> wattzahl = wattzahl;
  }
  void einschalten();
  void ausschalten();
  void dimmen(float lichtstaerke);
  void status();

  unsigned gib_wattzahl(){
    return this-> wattzahl;
  }
  bool ist_eingeschaltet();

//Konstruktor
  Lampe(unsigned wattzahl){
    this->wattzahl = wattzahl;
    this->eingeschaltet = false;
    this -> lichtstaerke = 0;
    this -> kaputt = false;
  }
};

int main(){
  Lampe l1(150);
  l1.einschalten();
  std::cout << l1.gib_wattzahl() << std::endl;
  l1.wechseln(400);
  std::cout << l1.gib_wattzahl() << std::endl;
}
