/*
Code von gromdimon
19.05.2023
*/

//**********************************************************************************************
// AUFGABE 2

// Implementiert die Binärsuche und implementiert zuvor einen von
// euch gewählten Sortieralgorithmus (bitte nicht die sort Funktion
// verwenden :D) mit einem struct „Person“, der die Attribute Name und
// Alter enthält. Es soll möglich sein nach dem Alter oder dem Namen
// von Personen zu suchen. Falls das gesuchte Element nicht enthalten
// ist, soll die Nachricht „Element wurde nicht gefunden“ auf dem
// Terminal ausgegeben werden.

#include <iostream>
#include <vector>
using namespace std;

struct Person {
  string Name;
  int Alter;
};

Person findPerson(vector<Person> persons, string name, int alter) {
  if (name != "") {
    for (int i = 0; i < static_cast<int>(persons.size()); i++) {
      if (persons[i].Name == name) {
        return persons[i];
      }
    }
  } else if (alter != -1) {
    for (int i = 0; i < static_cast<int>(persons.size()); i++) {
      if (persons[i].Alter == alter) {
        return persons[i];
      }
    }
  } else {
    cout << "The input data is invalid!" << endl;
  }
  Person Null = {"Null", 0};
  return Null;
}

int main() {
  vector<Person> persons = {
      {"Max", 20}, {"Moritz", 19}, {"Peter", 21}, {"Hans", 22}, {"Klaus", 23}};
  Person Nina = {"Nina", 20};

  Person foundPerson1 = findPerson(persons, "Max", -1);
  cout << "Suche Max, ausgabe: " << foundPerson1.Name << endl;
  Person foundPerson2 = findPerson(persons, "", 23);
  cout << "Suche Alter 23 (Klaus), ausgabe: " << foundPerson2.Name << endl;
  cout << "Suchen Nina, die nicht in List ist" << endl;
  Person foundPerson3 = findPerson(persons, "Nina", 20);
  cout << "Suche Nina, ausgabe: " << foundPerson3.Name << endl;
  Person falsh = findPerson(persons, "", 0);
  cout << "Falshe eingabe: " << falsh.Name << ", " << falsh.Alter << endl;

  return 0;
}