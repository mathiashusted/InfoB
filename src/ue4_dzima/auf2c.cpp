/*
Code von gromdimon
10.05.2023
*/

//**********************************************************************************************
// AUFGABE 2c

#include <algorithm>
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

vector<Item> getOptimalItems(int capacity, const vector<Item> &items) {
  vector<Item> optimalItems;

  int n = items.size();
  int remainingCapacity = capacity;

  // Iteriere über die Elemente in umgekehrter Reihenfolge
  for (int i = n - 1; i >= 0; --i) {
    // Wenn der optimale Wert sich ändert, dann wurde der aktuelle Gegenstand in
    // die optimale Lösung aufgenommen
    if (knapsackRecursive(remainingCapacity, items, i + 1) !=
        knapsackRecursive(remainingCapacity, items, i)) {
      optimalItems.push_back(items[i]);
      remainingCapacity -= items[i].weight;
    }
  }

  // Drehe den Vektor um, um die ursprüngliche Reihenfolge der Gegenstände
  // wiederherzustellen
  reverse(optimalItems.begin(), optimalItems.end());

  return optimalItems;
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
  int maxValue = knapsackRecursive(capacity, rucksack, rucksack.size());
  cout << "Maximaler Wert: " << maxValue << endl;

  // Berechne die Gegenstände, die in den Rucksack passen
  vector<Item> optimalItems = getOptimalItems(capacity, rucksack);
  cout << "Gegenstände, die in den Rucksack passen:" << endl;
  for (int i = 0; i < static_cast<int>(optimalItems.size()); i++) {
    cout << i << "\t\t" << optimalItems[i].weight << "\t\t"
         << optimalItems[i].value << endl;
  }

  return 0;
}
