/*
Code von gromdimon
26.04.2023
*/

//**********************************************************************************************
// AUFGABE 1a

#include <iostream>
using namespace std;

int main() {
  int num, min_num, max_num; // Deklarieren vars

  cout << "Geben Sie eine Folge von Zahlen ein (0 zum Beenden): ";
  cin >> num; // Lesen erste Zahl
  min_num = max_num = num;

  while (num !=
         0) { // Fragen nach neue Zahl, bevor user mit 0 den Programm beendet
    if (num < min_num) {
      min_num = num; // Update min
    }
    if (num > max_num) {
      max_num = num; // Update max
    }
    cout << "Geben Sie eine weitere Zahl ein (0 zum Beenden): ";
    cin >> num; // Lesen neue Zahl
  }

  cout << "Minimum: " << min_num << endl; // Ausgeben min
  cout << "Maximum: " << max_num << endl; // Ausgeben max

  return 0;
}
