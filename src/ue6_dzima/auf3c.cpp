/*
Code von gromdimon
26.05.2023
*/

//**********************************************************************************************
// AUFGABE 3c

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

vector<vector<int>> pairsum(vector<int> list) {
  vector<vector<int>> returnVec;
  for (int c = 0; c < static_cast<int>(list.size()); c++) {
    int a = 0;
    int b = static_cast<int>(list.size()) - 1;
    while (a < b) {
      if (list[a] + list[b] == list[c]) {
        vector<int> tmp;
        tmp.push_back(list[a]);
        tmp.push_back(list[b]);
        tmp.push_back(list[c]);
        returnVec.push_back(tmp);
        a++;
        b--;
      } else if (list[a] + list[b] < list[c]) {
        a++;
      } else {
        b--;
      }
    }
  }
  return returnVec;
}

int main() {
  vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<vector<int>> returnVec = pairsum(list);
  cout << "Ich nehme an, dass Liste schon sortiert ist!" << endl;
  cout << "Representieren a, b, c for a+b = c" << endl;
  for (int i = 0; i < static_cast<int>(returnVec.size()); i++) {
    cout << returnVec[i][0] << " " << returnVec[i][1] << " " << returnVec[i][2]
         << endl;
  }
  return 0;
}