//
// Created by gromdimon on 05.05.23.
//
#include <iostream>
#include <vector>
using namespace std;

// Schreibe ein C++ Programm, das den Benutzer nach der Größe eines Vektors und
// den Werten für den Vektor fragt. Das Programm soll dann die Anzahl der 1en und 3en im Vektor zählen und ausgeben. Zusätzlich soll das Programm überprüfen, ob der Vektor die Zahlenfolge "1989" enthält. Wenn ja, soll eine Nachricht ausgegeben werden, die besagt, dass das Album "1989" von Taylor Swift ein sehr gutes Album ist, andernfalls soll eine Nachricht ausgegeben werden, dass „1989“ nicht vorkommt.

void print(vector<int> input) {
  for (int i = 0; i < (static_cast<int>(input.size()) -1); i++) {
    cout << static_cast<int>(input[i]) << ' ';
  }
}

vector<int> reverse_vector(vector<int> vec) {
  int vector_size = static_cast<int>(vec.size());
  vector<int> rev_vec = vec;
  for (int i = 0; i < vector_size; i++) {
    rev_vec[vector_size - i] = vec[i];
  }
  return rev_vec;
}

int main() {
  vector<int> vec = {1, 2, 3, 4, 5};
  cout << "Your vector is: ";
  print(vec);
  vector<int> reverse = reverse_vector(vec);
  cout << "Your reversed vector: ";
  print(reverse);
}