/*
Code von gromdimon
16.06.2023
*/

//**********************************************************************************************
// AUFGABE 2

#include <iostream>
#include <vector>

// Lampe class
class Lampe{
private:
  unsigned wattzahl;
  bool eingeschaltet;
  float lichtstaerke;
  bool kaputt;

public:
  void wechseln(unsigned wattzahl) {
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
  void status() const {
    std::cout << "Wattzahl: " << this->wattzahl << std::endl;
    std::cout << "Eingeschaltet: " << this->eingeschaltet << std::endl;
    std::cout << "Lichtstaerke: " << this->lichtstaerke << std::endl;
    std::cout << "Kaputt: " << this->kaputt << std::endl;
  };
  unsigned gib_wattzahl() const {
    return this-> wattzahl;
  }
  bool ist_eingeschaltet() const {
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

// Quicksort algorithm
void quicksort(std::vector<Lampe>& lampen) {
    if (static_cast<int>(lampen.size()) <= 1) {
        return;
    }

    // Choose pivot element
    int pivotIndex = static_cast<int>(lampen.size()) / 2;
    Lampe pivot = lampen[pivotIndex];

    // Partition the vector
    std::vector<Lampe> smaller;
    std::vector<Lampe> larger;
    for (int i = 0; i < static_cast<int>(lampen.size()); i++) {
        if (i == pivotIndex) {
            continue;
        }
        if (lampen[i] < pivot) {
            smaller.push_back(lampen[i]);
        } else {
            larger.push_back(lampen[i]);
        }
    }

    // Recursively apply quicksort to sub-vectors
    quicksort(smaller);
    quicksort(larger);

    // Concatenate sorted sub-vectors
    lampen.clear();
    lampen.insert(lampen.end(), smaller.begin(), smaller.end());
    lampen.push_back(pivot);
    lampen.insert(lampen.end(), larger.begin(), larger.end());
};

int main() {
    std::vector<Lampe> lampen;
    for (int i = 1; i < 11; i++) {
        lampen.push_back(Lampe(i * 100));
    }

    quicksort(lampen);

    for (const auto& lampe : lampen) {
        lampe.status();
        std::cout << std::endl;
    }

    return 0;
}