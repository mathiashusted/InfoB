/*
Code von gromdimon
16.06.2023
*/

//**********************************************************************************************
// AUFGABE 1


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
  void einschalten() {
    this->eingeschaltet = true;
  };
  void ausschalten() {
    this->eingeschaltet = false;
  };
  void dimmen(float lichtstaerke) {
    this->lichtstaerke = lichtstaerke;
  };
  void status() {
    std::cout << "Wattzahl: " << this->wattzahl << std::endl;
    std::cout << "Eingeschaltet: " << this->eingeschaltet << std::endl;
    std::cout << "Lichtstaerke: " << this->lichtstaerke << std::endl;
    std::cout << "Kaputt: " << this->kaputt << std::endl;
  };
  unsigned gib_wattzahl() const {
    return this-> wattzahl;
  }
  bool ist_eingeschaltet() {
    return this->eingeschaltet;
  };

  //Konstruktor
  Lampe(unsigned wattzahl){
    this->wattzahl = wattzahl;
    this->eingeschaltet = false;
    this -> lichtstaerke = 0;
    this -> kaputt = false;
  }

  //Destruktor
  ~Lampe(){
    std::cout << "Lampe wird zerstoert" << std::endl;
  }

  bool operator < (const Lampe& l) const{
    return this->wattzahl < l.gib_wattzahl();
  }
};

int main(){
  Lampe l1(150);
  Lampe l2(200);
  l1.einschalten();
  std::cout << l1.gib_wattzahl() << std::endl;
  l1.wechseln(400);
  std::cout << l1.gib_wattzahl() << std::endl;
  std::cout << "Verglechen zwei Lampen" << std::endl;
  bool result = l1 < l2;
  std::cout << l1.gib_wattzahl() << "<" << l2.gib_wattzahl() << " ist " << result << std::endl;
}
