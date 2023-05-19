/*
Code von gromdimon
19.05.2023
*/

//**********************************************************************************************
// AUFGABE 3

// a) Wendet auf die Liste {s,p,e,a,k,n,o,w,t,v} den Tri-Mergesort
// Algorithmus an, so dass die Elemente lexikografisch aufsteigend
// sortiert sind. Tri-Mergesort funktioniert wie Mergesort, nur wird
// beim Teilprozess in drei (anstelle von zwei) annährend gleich
// große Listen geteilt. Diese werden rekursiv sortiert und n einem
// gemeinsamen Merge-Prozess wieder zu einer sortierten Liste
// zusammengefasst.
// b) Analysiert den Trimergesort Algorithmus.

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<char> &list, int left, int middle, int right) {
  int i = left;
  int j = middle + 1;
  vector<char> temp;
  while (i <= middle && j <= right) {
    if (list[i] < list[j]) {
      temp.push_back(list[i]);
      i++;
    } else {
      temp.push_back(list[j]);
      j++;
    }
  }
  while (i <= middle) {
    temp.push_back(list[i]);
    i++;
  }
  while (j <= right) {
    temp.push_back(list[j]);
    j++;
  }
  for (int i = left; i <= right; i++) {
    list[i] = temp[i - left];
  }
}

void triMergeSort(vector<char> &list, int left, int right) {
  if (left < right) {
    int middle1 = left + (right - left) / 3;
    int middle2 = left + 2 * (right - left) / 3;
    triMergeSort(list, left, middle1);
    triMergeSort(list, middle1 + 1, middle2);
    triMergeSort(list, middle2 + 1, right);
    merge(list, left, middle1, right);
  }
}

int main() {
  vector<char> list = {'s', 'p', 'e', 'a', 'k', 'n', 'o', 'w', 't', 'v'};
  triMergeSort(list, 0, static_cast<int>(list.size()) - 1);
  for (char c : list) {
    cout << c << " ";
  }
  cout << endl;
  return 0;
}