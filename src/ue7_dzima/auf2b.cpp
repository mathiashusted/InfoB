/*
Code von gromdimon
02.06.2023
*/

//**********************************************************************************************
// AUFGABE 2b

#include <iostream>
using namespace std;

// Beschreiben Sie verbal wie das Verhalten Call-by-Reference mit Hilfe von
// Pointern simuliert werden kann. Schreiben Sie ein C++-Programm, welches Ihre
// Beschreibung umsetzt.

// Call-by-Reference mit Pointern simulieren:
// 1. Pointer auf Variable erstellen
// 2. Pointer an Funktion übergeben
// 3. Pointer dereferenzieren und Wert ändern

void change(int *a) { *a = 5; }

int main() {
  int a = 0;
  int *ptr = &a;
  cout << "a = " << a << endl;
  change(ptr);
  cout << "a = " << a << endl;
  return 0;
}