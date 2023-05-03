/*
Code von gromdimon
26.04.2023
*/

//**********************************************************************************************
// AUFGABE 1c


#include <iostream>
using namespace std;

int main() {
  int num, min_num, max_num, sum = 0, count = 0;   // Deklarieren vars
  double avg;
  
  cout << "Geben Sie eine Folge von Zahlen ein (9999 zum Beenden): ";
  cin >> num;   // Lesen ersten Zahl
  min_num = max_num = num;
  
  while (num != 9999) {   // Auswerten Zahlen bevor 9999 auftritt
    count++;   // Calculieren Anzahl
    sum += num;   // Calculieren sum
    if (num < min_num) {   // Update min
      min_num = num;
    }
    if (num > max_num) {   // Update max
      max_num = num;
    }
    cout << "Geben Sie eine weitere Zahl ein (9999 zum Beenden): ";
    cin >> num;
  }
  
  if (count > 0) {
    avg = static_cast<double>(sum) / static_cast<double >(count);   // Auswerten avg
    cout << "Minimum: " << min_num << endl;
    cout << "Maximum: " << max_num << endl;
    cout << "Mittelwert: " << avg << endl;
  } else {
    cout << "Es wurden keine Zahlen eingegeben." << endl;   // Parse / 0
  }
  
  return 0;
}
