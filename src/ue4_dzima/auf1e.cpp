/*
Code von gromdimon
10.05.2023
*/

//**********************************************************************************************
// AUFGABE 1e

#include <algorithm>
#include <iostream>
#include <vector>

// Funktion, um die Dateien nach ihrer Größe absteigend zu sortieren
void sortFiles(std::vector<int> &files) {
  int n = files.size();

  for (int i = 1; i < n; ++i) {
    int key = files[i];
    int j = i - 1;

    while (j >= 0 && files[j] < key) {
      files[j + 1] = files[j];
      j = j - 1;
    }

    files[j + 1] = key;
  }
}

// Funktion, um die erwartete Zugriffszeit zu berechnen
int calculateAccessTime(const std::vector<int> &files) {
  int accessTime = 0;
  int n = files.size();

  for (int i = 0; i < n; ++i) {
    accessTime += files[i];
  }

  return accessTime;
}

int main() {
  std::vector<int> files = {4, 2, 5, 2, 6};

  // Sortiere die Dateien absteigend nach ihrer Größe
  sortFiles(files);

  // Berechne die erwartete Zugriffszeit
  int accessTime = calculateAccessTime(files);

  // Gib die erwartete Zugriffszeit aus
  std::cout << "Erwartete Zugriffszeit: " << accessTime << std::endl;

  return 0;
}
