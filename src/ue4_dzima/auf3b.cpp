/*
Code von gromdimon
10.05.2023
*/

//**********************************************************************************************
// AUFGABE 3b

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr, bool ascending) {
  int n = arr.size();

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      // Vergleiche benachbarte Elemente und tausche sie, falls sie in der
      // falschen Reihenfolge sind
      if (ascending ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main() {
  vector<int> arr = {5, 2, 8, 12, 3};

  // Sortiere den Vektor aufsteigend
  bubbleSort(arr, true);

  // Gib den sortierten Vektor aus
  for (int num : arr) {
    cout << num << " ";
  }

  return 0;
}
