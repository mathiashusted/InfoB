/*
Code von gromdimon
26.04.2023
*/

//**********************************************************************************************
// AUFGABE 2b


#include <iostream>
using namespace std;

int main() {
  int num;   // Deklarieren
  cout << "Geben Sie eine Einschraenkung: ";
  cin >> num;   // Lesen Zahl
 
  for (int i = 0; i <= num; i++) {   // Gehen durch jeden Element
    // Ueberpruefen die Zahl auf teilbarkeit
    // Zuerst die complexeste und danach die einfachste
    if (i % 3 == 0 && i % 5 == 0 && i % 7 == 0) {
      cout << "bliblablub" << endl;
    } else if (i % 3 == 0 && i % 5 == 0) {
      cout << "blibla" << endl;
    } else if (i % 3 == 0 && i % 7 == 0) {
      cout << "bliblub" << endl;
    } else if (i % 5 == 0 && i % 7 == 0) {
      cout << "blablub" << endl;
    } else if (i % 3 == 0) {
      cout << "bli" << endl;
    } else if (i % 5 == 0) {
      cout << "bla" << endl;
    } else if (i % 7 == 0) {
      cout << "blub" << endl;
    }
  }
  
  return 0;
}
