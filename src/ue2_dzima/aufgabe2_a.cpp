/*
Code von gromdimon
26.04.2023
*/

//**********************************************************************************************
// AUFGABE 2a

#include <iostream>
using namespace std;

int main() {
  int zahl, qsumme = 0; // Deklarieren vars

  // Quersumme mit for-Schleife berechnen
  cout << "Geben Sie eine Zahl ein: ";
  cin >> zahl; // Lesen Zahl
  for (; zahl > 0; zahl /= 10) {
    qsumme += zahl % 10;
  }
  cout << "Die Quersumme der Zahl (mit for-Schleife) ist " << qsumme << endl;

  // Quersumme mit while-Schleife berechnen
  qsumme = 0;
  cout << "Geben Sie eine weitere Zahl ein: ";
  cin >> zahl; // Lesen Zahl
  while (zahl > 0) {
    qsumme += zahl % 10;
    zahl /= 10;
  }
  cout << "Die Quersumme der Zahl (mit while-Schleife) ist " << qsumme << endl;

  return 0;
}
