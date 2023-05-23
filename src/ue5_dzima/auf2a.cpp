/*
Code von gromdimon
17.05.2023
*/

//**********************************************************************************************
// AUFGABE 2a

// Wir habe in der Vorlesung eine Möglichkeit kennengelernt das Minimum einer
// Liste zu bestimmen. In dieser Aufgabe geht es um eine alternative Möglichkeit
// dafür. Es soll ein Turniermodus betrachtet werden. Dazu werden in der ersten
// Runde, immer zwei benachbarte Zahlen miteinander verglichen. Die kleinere
// „gewinnt“ und kommt in die nächste Runde. In dieser Art und Weise werden die
// Zahlen weiter verglichen, bis nach der letzten Runde nur noch eine Zahl übrig
// ist.
// (a) Implementieren Sie die oben beschriebene Möglichkeit das Minimum zu
// finden.

#include <iostream>
#include <vector>
using namespace std;

int findMinimum(vector<int> nums) {
  int size = nums.size();
  int i = 0;
  int j = 1;

  while (size > 1) {
    if (nums[i] < nums[j]) {
      nums.erase(nums.begin() + j);
    } else {
      nums.erase(nums.begin() + i);
    }
    size--;
  }

  return nums[0];
}

vector<int> alternativeFindMinimum(vector<int> nums) {
  int size = static_cast<int>(nums.size());

  if (size == 1) {
    return nums;
  } else if (size == 2) {
    return nums[0] < nums[1] ? vector<int>{nums[0]} : vector<int>{nums[1]};
  } else {
    vector<int> numsleft(nums.begin(), nums.begin() + size / 2);
    vector<int> numsright(nums.begin() + size / 2, nums.end());
    vector<int> minimumLeft = alternativeFindMinimum(numsleft);
    vector<int> minimumRight = alternativeFindMinimum(numsright);
    return alternativeFindMinimum(
        minimumLeft[0] < minimumRight[0] ? minimumLeft : minimumRight);
  }
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

  cout << "Die Eingabeliste: "
       << "\n1, 2, 3, 4, 5, 6, 7" << endl;

  cout << "Das Minimum: " << endl;
  cout << findMinimum(nums) << endl;

  cout << "Das Minimum (alternative): " << endl;
  cout << alternativeFindMinimum(nums)[0] << endl;

  return 0;
}
