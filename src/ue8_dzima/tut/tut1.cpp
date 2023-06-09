/*
Code von gromdimon
09.06.2023
*/

//**********************************************************************************************
// AUFGABE 1

#include <iostream>
using namespace std;

// Aufgabe 1: Heapsort
// Wendet Heapsort einmal in-place und einmal out-of-place auf das folgende Array an:
// [17, 3, 42, 10, 6, 2, 25, 11]

// in-place
void heap_in(int *arr, int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest]) largest = l;
  if (r < n && arr[r] > arr[largest]) largest = r;

  if (largest != i) {
    swap(arr[i], arr[largest]);
    heap_in(arr, n, largest);
  }
}

void heapSort(int *arr, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) heap_in(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heap_in(arr, i, 0);
  }
}

// out-of-place
void heap_out(int *arr, int *sorted, int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest]) largest = l;
  if (r < n && arr[r] > arr[largest]) largest = r;

  if (largest != i) {
    swap(arr[i], arr[largest]);
    heap_out(arr, sorted, n, largest);
  }
}

void heapSort(int *arr, int *sorted, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) heap_out(arr, sorted, n, i);

  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    sorted[i] = arr[i];
    heap_out(arr, sorted, i, 0);
  }
}

int main() {
  int arr[] = {17, 3, 42, 10, 6, 2, 25, 11};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "in-place:" << endl;
  heapSort(arr, n);
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;

  cout << "out-of-place:" << endl;
  int sorted[n];
  heapSort(arr, sorted, n);
  for (int i = 0; i < n; i++) cout << sorted[i] << " ";
  cout << endl;

  return 0;
}