/*
Code von gromdimon
3.05.2023
*/

//**********************************************************************************************
// AUFGABE 1b

#include <algorithm>
#include <iostream>
#include <string>

void function(std::string &str) {
  std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

void toUpperCase(std::string &str) {
  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = str[i] - 'a' + 'A';
    }
  }
}

int main() {
  std::string str;
  std::cout << "Put here an example string: ";
  std::cin >> str;

  std::cout << "The string before changes: " << str << std::endl;
  toUpperCase(str);
  std::cout << "The string after changes: " << str << std::endl;

  return 0;
}
