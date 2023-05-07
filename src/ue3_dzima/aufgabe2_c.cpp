/*
Code von gromdimon
3.05.2023
*/

//**********************************************************************************************
// AUFGABE 2c

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// Vor: Message (string)
// Erg: Paar von Vektoren (char, int)
// Eff: Berechnet Histogramm von Buchstaben in Message
pair<vector<char>, vector<int>> calc_letters(string msg) {
  vector<char> letter_chars; // Declarierung von Vektoren
  vector<int> letter_count;

  for (size_t i = 0; i < msg.length(); i++) {
    bool foundChar = false; // Declarierung von Variablen
    int charPos = 0;
    char current_char = msg[i];

    // Prooving if the charakter is in the vector
    for (size_t i = 0; i < letter_chars.size(); i++) {
      if (letter_chars[i] == current_char) {
        foundChar = true;
        charPos = i;
        break;
      }
    }

    // If the letter exists, count occurance
    // If not - add new assignment
    if (foundChar) {
      letter_count[charPos] += 1;
    } else {
      letter_chars.push_back(current_char);
      letter_count.push_back(1);
    }
  }

  return make_pair(letter_chars, letter_count);
}

// Vor: Vektoren (char, int)
// Erg: Keine
// Eff: Gibt Histogramm von Buchstaben in Console aus
void represent_histogramm(vector<char> letter_chars, vector<int> letter_count) {
  for (size_t i = 0; i < letter_chars.size(); i++) {
    cout << letter_chars[i] << ":" << letter_count[i] << ", "; // Output
  }
  cout << endl;
}

int main() {
  string line;
  string filename = "moby.txt";
  ifstream file(filename);

  // Reading file
  if (file.is_open()) {
    string file_contents((istreambuf_iterator<char>(file)),
                         istreambuf_iterator<char>());
    file.close(); // Closing file

    auto histogramm_pair = calc_letters(file_contents);
    vector<char> letter_chars = histogramm_pair.first;
    vector<int> letter_count = histogramm_pair.second;

    represent_histogramm(letter_chars, letter_count);
  } else { // If file is not open
    cout << "Unable to open file" << endl;
  }

  return 0;
}
