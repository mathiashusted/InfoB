/*
Code von gromdimon
3.05.2023
*/

//**********************************************************************************************
// AUFGABE 3a

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

int main() {
  angestellter hans = {"Hans Müller", 12345, Abteilung::IT, 5000.0};

  std::cout << "Name: " << hans.name << std::endl;
  std::cout << "Personalnummer: " << hans.personalnummer << std::endl;
  std::cout << "Abteilung: ";

  switch (hans.abteilung) {
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
  std::cout << "Gehalt: " << hans.gehalt << std::endl;

  return 0;
}