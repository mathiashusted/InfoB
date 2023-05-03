/*
Code von gromdimon
3.05.2023
*/

//**********************************************************************************************
// AUFGABE 2a

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

pair<vector<char>, vector<int>> calc_letters(string msg) {
  vector<char> letter_chars;
  vector<int> letter_count;

  for (size_t i = 0; i < msg.length(); i++) {
    bool foundChar = false;
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

void represent_histogramm(vector<char> letter_chars, vector<int> letter_count) {
  for (size_t i = 0; i < letter_chars.size(); i++) {
    cout << letter_chars[i] << ":" << letter_count[i] << ", ";
  }
  cout << endl;
}

int main() {
  string msg;
  cout << "Put here a message (only string!) for histogramm: ";
  cin >> msg;

  auto histogramm_pair = calc_letters(msg);
  vector<char> letter_chars = histogramm_pair.first;
  vector<int> letter_count = histogramm_pair.second;

  represent_histogramm(letter_chars, letter_count);

  return 0;
}
