/*
Code von gromdimon
10.05.2023
*/

//**********************************************************************************************
// AUFGABE 2b

#include <iostream>
#include <vector>
using namespace std;

struct Item {
  int weight; // Gewicht des Gegenstands
  int value;  // Wert des Gegenstands

  Item(int weight, int value) : weight(weight), value(value) {}
};

int knapsackRecursive(int capacity, const vector<Item> &items, int n) {
  // Basisfall: Wenn keine Gegenstände oder Kapazität erreicht ist, ist der Wert
  // 0
  if (n == 0 || capacity == 0) {
    return 0;
  }

  // Wenn das Gewicht des aktuellen Elements das Fassungsvermögen überschreitet,
  // schließen wir es aus
  if (items[n - 1].weight > capacity) {
    return knapsackRecursive(capacity, items, n - 1);
  }

  // Rückgabe des Maximums zwischen dem Fall, in dem das Element ausgewählt
  // wird, und dem Fall, in dem es ausgeschlossen wird
  return max(
      items[n - 1].value +
          knapsackRecursive(capacity - items[n - 1].weight, items, n - 1),
      knapsackRecursive(capacity, items, n - 1));
}

int main() {
  // Erstelle ein Array mit den Gegenständen
  // Testieren knapsackRecursive algorithm
  vector<Item> rucksack;
  rucksack.push_back(Item(1, 2));
  rucksack.push_back(Item(2, 3));
  rucksack.push_back(Item(3, 4));
  rucksack.push_back(Item(4, 5));

  cout << "Gegenstand"
       << "\t"
       << "Gewicht"
       << "\t"
       << "Wert" << endl;
  for (int i = 0; i < static_cast<int>(rucksack.size()); i++) {
    cout << i << "\t\t" << rucksack[i].weight << "\t\t" << rucksack[i].value
         << endl;
  }

  // Berechne den maximalen Wert des Rucksacks
  int capacity = 5;
  int n = rucksack.size();
  int maxValue = knapsackRecursive(capacity, rucksack, n);

  // Gib den maximalen Wert des Rucksacks aus
  cout << "Maximaler Wert des Rucksacks: " << maxValue << endl;

  return 0;
}