/*
Code von gromdimon
3.05.2023
*/

//**********************************************************************************************
// AUFGABE 1a

#include <iostream>
#include <string>
using namespace std;

// Vor: String, char, char
// Erg: Keine
// Eff: Ersetzt alle Vorkommen von char a in String str durch char b
void function(string &str, char a, char b) {
  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == a) {
      str[i] = b;
    }
  }
}

// Vor: Keine
// Erg: Keine
// Eff: Liest einen String und zwei chars ein, und gibt den String mit den
// ersetzen chars aus
int main() {
  string str;
  char a, b;
  cout << "Put here an example string: ";
  cin >> str;
  cout << "Charakter to be changed: ";
  cin >> a;
  cout << "Charakter to change to: ";
  cin >> b;

  cout << "The string before changes: " << str << endl;
  function(str, a, b);
  cout << "The string after changes: " << str << endl;

  return 0;
}
