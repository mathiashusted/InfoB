/*
Code von gromdimon
10.05.2023
*/

//**********************************************************************************************
// AUFGABE 3d

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

// Funktion zum Überprüfen, ob die Liste sortiert ist
bool isSorted(const vector<int> &arr) {
  int n = arr.size();

  for (int i = 0; i < n - 1; ++i) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }

  return true;
}

// Funktion zum Mischen der Elemente in der Liste
void shuffle(vector<int> &arr) {
  random_device rd;
  mt19937 gen(rd());

  shuffle(arr.begin(), arr.end(), gen);
}

// Bogosort-Algorithmus
void bogosort(vector<int> &arr) {
  while (!isSorted(arr)) {
    shuffle(arr);
  }
}

int main() {
  vector<int> arr = {5, 2, 8, 12, 3};

  // Sortiere den Vektor mit Bogosort
  bogosort(arr);

  // Gib den sortierten Vektor aus
  for (int num : arr) {
    cout << num << " ";
  }

  return 0;
}
