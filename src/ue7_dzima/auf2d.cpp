/*
Code von gromdimon
02.06.2023
*/

//**********************************************************************************************
// AUFGABE 2d

#include <iostream>
using namespace std;

// Schreiben Sie eine Funktion, die vom Nutzer eine Anzahl k von Zahlen
// einliest. Dabei soll zunächst die Anzahl der Zahlen die der Benutzer eingeben
// will abgefragt werden. Dann sollen die Zahlen nach und nach in ein array
// eingelesen werden und die Summe der Zahlen wird zurückgegeben. Verwenden Sie
// primitive Arrays und dynamische Allozierung.

int main() {
  int k;
  int sum = 0;
  cout << "Wie viele Zahlen wollen Sie eingeben?" << endl;
  cin >> k;
  int *arr = new int[k];

  for (int i = 0; i < k; i++) {
    cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein:" << endl;
    cin >> arr[i];
    sum += arr[i];
  }

  cout << "Die Summe der Zahlen ist: " << sum << endl;
  cout << "Array: ";
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  delete[] arr;
  return 0;
}