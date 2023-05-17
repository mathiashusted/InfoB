/*
Code von gromdimon
17.05.2023
*/

//**********************************************************************************************
// AUFGABE 2a

#include <iostream>
#include <vector>
using namespace std;

int findMinimum(std::vector<int> &nums) {
  int n = nums.size();

  while (n > 1) {
    int round = n / 2;

    for (int i = 0; i < round; i++) {
      int j = 2 * i;

      if (nums[j] > nums[j + 1]) {
        nums[i] = nums[j + 1];
      } else {
        nums[i] = nums[j];
      }
    }

    if (n % 2 != 0) {
      nums[round] = nums[n - 1];
      round++;
    }

    n = round;
  }

  return nums[0];
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  cout << findMinimum(nums) << endl;

  return 0;
}
