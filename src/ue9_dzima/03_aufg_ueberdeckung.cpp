/* Informatik B Sommer 2023
 * 09.06.2023
 * Katharina Klost
 */

// Kompilieren: g++ -std=c++14 -Wall -Wextra -Werror -pedantic
// 03_aufg_ueberdeckung.cpp -o aufg2

#include <iostream>

class A {
public:
  void func1() { std::cout << "A1" << std::endl; }

  virtual void func2() { std::cout << "A2" << std::endl; }

  virtual ~A() {}
};

class B : public A {
public:
  void func1();

  void func2() { std::cout << "B2" << std::endl; }
};

// B::func1(){
//    std::cout << "B1" << std::endl;
//  }

void tutDinge(A &a) {
  a.func1();
  a.func2();
}

void tutDinge2(A a) {
  a.func1();
  a.func2();
}

int main() {
  A v1 = A();
  B v2 = B();
  A *v3 = new B();

  // statische und dynamischer Typ stimmen überein, es wird immer die Methode
  // von A aufgerufen
  std::cout << "Expliziter Aufruf v1" << std::endl;
  v1.func1();
  v1.func2();

  // statischer und dynamischer Typ stimmen überein, es wird immer die Methode
  // von B aufgerufen
  std::cout << "Expliziter Aufruf v2" << std::endl;
  // v2.func1();
  v2.func2();

  // statischer Typ A, dynamischer Typ B, da func1 nicht virtualisiert ist, wird
  // func1 von A aufgerufen da func2 virtualisiert ist, wird func2 von B
  // aufgerufen
  std::cout << "Expliziter Aufruf v3" << std::endl;
  // v3->func1();
  v3->func2();

  // da der statische und dynamische Typ von v1 beide A sind, passen statischer
  // und dynamsicher Typ von a im Aufruf von tutDinge zusammen und es wird immer
  // die Funktion von A aufgerufen
  std::cout << "tutDinge(v1)" << std::endl;
  tutDinge(v1);

  // statischer und dynamischer Typ von v2 sind beide B. Der Typ des Parameters
  // von tutDinge ist jedoch A&. Daher ist der statische Typ der Variable a in
  // tutDinge A, der dynamische Typ aber B. da func1 nicht virtualisiert ist,
  // wird func1 von A aufgerufen da func2 virtualisiert ist, wird func2 von B
  // aufgerufen
  std::cout << "tutDinge(v2)" << std::endl;
  tutDinge(v2);

  // Typ von v2 ist A, genauso wie der Paramter von tutDinge2, also keine
  // Probleme zu erwarten
  std::cout << "tutDinge2(v1)" << std::endl;
  tutDinge2(v1);

  // dynamische Bindung funktioniert nur mit Pointern oder Referenzen. Da
  // tutDinge2 call-by-value macht, passiert object slicing und die Funktion von
  // A wird beide male aufgerufen. Bei dynamischer Bindung IMMER Pointer oder
  // Referenzen verwenden
  std::cout << "tutDinge2(v2)" << std::endl;
  tutDinge2(v2);

  delete v3;
}
