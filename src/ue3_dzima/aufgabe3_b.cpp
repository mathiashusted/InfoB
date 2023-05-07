/*
Code von gromdimon
3.05.2023
*/

//**********************************************************************************************
// AUFGABE 3b

#include <iostream>
using namespace std;

enum class Abteilung {
  IT,
  Vertrieb,
  Personal,
  Buchhaltung,
};

struct angestellter {
  std::string name;
  int personalnummer;
  Abteilung abteilung;
  double gehalt;
};

// Vor: Keine
// Erg: Angestellter
// Eff: Liest einen Angestellten ein, und gibt ihn aus
angestellter read_angestellter() {
  angestellter a;

  // Read the name
  std::cout << "Name: ";
  std::getline(std::cin, a.name);

  // Read the personalnummer
  std::cout << "Personalnummer: ";
  std::cin >> a.personalnummer;

  // Read the abteilung
  std::cout << "Abteilung (IT=0, Vertrieb=1, Personal=2, Buchhaltung=3): ";
  int abteilung;
  std::cin >> abteilung;
  a.abteilung = static_cast<Abteilung>(abteilung);

  // Read the gehalt
  std::cout << "Gehalt: ";
  std::cin >> a.gehalt;

  return a;
}

// Vor: Keine
// Erg: Keine
// Eff: Liest einen Angestellten ein, und gibt ihn aus
int main() {
  angestellter a = read_angestellter();

  std::cout << "Angestellter: " << a.name << std::endl;
  std::cout << "Personalnummer: " << a.personalnummer << std::endl;
  std::cout << "Abteilung: ";

  switch (a.abteilung) {
  case Abteilung::IT:
    std::cout << "IT";
    break;
  case Abteilung::Vertrieb:
    std::cout << "Vertrieb";
    break;
  case Abteilung::Personal:
    std::cout << "Personal";
    break;
  case Abteilung::Buchhaltung:
    std::cout << "Buchhaltung";
    break;
  }

  std::cout << std::endl;
  std::cout << "Gehalt: " << a.gehalt << std::endl;

  return 0;
}