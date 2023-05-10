/*
Code von gromdimon
10.05.2023
*/

//**********************************************************************************************
// AUFGABE 2a

#include <iostream>
#include <vector>
using namespace std;

struct Item {
  int weight; // Gewicht des Gegenstands
  int value;  // Wert des Gegenstands

  Item(int weight, int value) : weight(weight), value(value) {}
};

int main() {
  // Erstelle ein Array mit den Gegenständen
  // Darstellen Array mit 4 Gegenständen
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

  return 0;
}
