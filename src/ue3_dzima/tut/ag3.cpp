/*
Code von gromdimon
12.05.2023
*/

//**********************************************************************************************
// AUFGABE 3

#include <iostream>
#include <vector>
using namespace std;

// Implementiert eine Funktion, die diese Voraussetzungen erfüllt: Als Eingabe
// bekommt die Funktion zwei Vektoren aus Zahlen. Es sollen alle Kombinationen
// von Paaren aufgelistet werden, wobei jeweils eine Zahl aus dem ersten Vektor
// und die zweite Zahl aus dem zweiten Vektor stammen. Diese Paare sollen in
// einem Vektor gespeichert und ausgegeben werden. Bsp.: {1, 2, 3}{4, 5} → {{1,
// 4}, {1, 5}, {2, 4}, {2, 5}, {3, 4}, {3, 5}}

vector<vector<int>> combine(vector<int> a, vector<int> b) {
  vector<vector<int>> result;
  for (int i = 0; i < static_cast<int>(a.size()); i++) {
    for (int j = 0; j < static_cast<int>(b.size()); j++) {
      vector<int> temp;
      temp.push_back(a[i]);
      temp.push_back(b[j]);
      result.push_back(temp);
    }
  }
  return result;
}

int main() {
  vector<int> a = {1, 2, 3};
  vector<int> b = {4, 5};
  vector<vector<int>> result = combine(a, b);
  
  for (int i = 0; i < static_cast<int>(result.size()); i++) {
    cout << "{";
    for (int j = 0; j < static_cast<int>(result[i].size()); j++) {
      cout << result[i][j];
      if (j != static_cast<int>(result[i].size()) - 1)
        cout << ", ";
    }
    cout << "}";
    if (i != static_cast<int>(result.size()) - 1)
      cout << ", ";
  }
  cout << endl;

  return 0;
}