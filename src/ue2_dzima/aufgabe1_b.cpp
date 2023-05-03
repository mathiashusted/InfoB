/*
Code von gromdimon
26.04.2023
*/

//**********************************************************************************************
// AUFGABE 1b

#include <iostream>
using namespace std;

int main() {
  int n, num, min_num, max_num, sum = 0; // Deklarieren vars
  double avg;

  cout << "Wie viele Zahlen moechten Sie eingeben? ";
  cin >> n; // Lesen Anzahl
  cout << "Geben Sie eine Folge von " << n << " Zahlen ein: ";
  cin >> num;              // Erste Zahl
  min_num = max_num = num; // Min, max update
  sum += num;

  for (int i = 1; i < n;
       i++) { // Starten nicht von 0, da erste num schon gelesen wurde!
    cout << "Und noch: ";
    cin >> num;
    sum += num;
    if (num < min_num) { // Update min
      min_num = num;
    }
    if (num > max_num) { // Update max
      max_num = num;
    }
  }

  avg = static_cast<double>(sum) / static_cast<double>(n); // Calculieren mean
  cout << "Minimum: " << min_num << endl;                  // Ausgabe min
  cout << "Maximum: " << max_num << endl;                  // Ausgabe max
  cout << "Mittelwert: " << avg << endl;                   // Ausgabe mean

  return 0;
}
