/*
Code von gromdimon
12.05.2023
*/

//**********************************************************************************************
// AUFGABE 1

#include <iostream>
using namespace std;

// Implementiert eine Funktion, die einen int x bekommt und die x-te
// Fibonaccizahl zurückgibt.

int fib(int x) {
  if (x == 0)
    return 0;
  if (x == 1)
    return 1;
  return fib(x - 1) + fib(x - 2);
}

int main() {
  int x;
  cout << "Gib eine Zahl ein: ";
  cin >> x;
  cout << "Die " << x << "-te Fibonaccizahl ist " << fib(x) << endl;

  return 0;
}