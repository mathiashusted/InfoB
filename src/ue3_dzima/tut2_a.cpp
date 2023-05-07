/*
Code von gromdimon
5.05.2023
*/

//**********************************************************************************************
// TUTORIUM 2, a

#include <iostream>
#include <vector>
using namespace std;

// Implementiert ein C++ Programm, welches ein Vektor bekommt und die Einträge des
// Vektors umdreht. Die vorimplimentierte Funktion reverse darf natürlich nicht benutzt
// werden.

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