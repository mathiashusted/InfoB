/*
Code von gromdimon
11.06.2023
*/

//**********************************************************************************************
// AUFGABE 3b

// (b) Implementieren Sie mergesort und binaersuche für Objekte vom Typ
// schluesselWertPaar.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T, typename U> class schluesselWertPaar {
private:
  T schluessel;
  U wert;

public:
  schluesselWertPaar() {} // Default constructor
  /*
  Voraussetzung: Keine
  Effekt: Ein schluesselWertPaar Objekt mit Schlüssel schluessel und Wert wert
  ist erzeugt Ergebnis: Keins
  */
  schluesselWertPaar(T schluessel, U wert) {
    this->schluessel = schluessel;
    this->wert = wert;
  }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Der Schlüssel des schluesselWertPaar Objekts ist geliefert
  */
  T getSchluessel() const { return schluessel; }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: Der Wert des schluesselWertPaar Objekts ist geliefert
  */
  U getWert() const { return wert; }
  /*
  Voraussetzung: Keine
  Effekt: Der Schlüssel des schluesselWertPaar Objekts ist auf schluessel
  gesetzt Ergebnis: Keins
  */
  void setSchluessel(T schluessel) { this->schluessel = schluessel; }
  /*
  Voraussetzung: Keine
  Effekt: Der Wert des schluesselWertPaar Objekts ist auf wert gesetzt
  Ergebnis: Keins
  */
  void setWert(U wert) { this->wert = wert; }
  /*
  Voraussetzung: Keine
  Effekt: Keins
  Ergebnis: true, wenn der Schlüssel des schluesselWertPaar Objekts kleiner als
  der Schlüssel des anderen schluesselWertPaar Objekts ist, sonst false
  */
  bool operator<(const schluesselWertPaar &other) const {
    return schluessel < other.schluessel;
  }
};

// Merge function for merge sort
template <typename T, typename U>
void merge(std::vector<schluesselWertPaar<T, U>> &arr, int left, int mid,
           int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Create temporary arrays
  std::vector<schluesselWertPaar<T, U>> leftArr(n1);
  std::vector<schluesselWertPaar<T, U>> rightArr(n2);

  // Copy data to temporary arrays
  for (int i = 0; i < n1; i++)
    leftArr[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    rightArr[j] = arr[mid + 1 + j];

  // Merge the temporary arrays back into arr[l..r]
  int i = 0;    // Initial index of first subarray
  int j = 0;    // Initial index of second subarray
  int k = left; // Initial index of merged subarray

  while (i < n1 && j < n2) {
    if (leftArr[i] < rightArr[j]) {
      arr[k] = leftArr[i];
      i++;
    } else {
      arr[k] = rightArr[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of leftArr, if any
  while (i < n1) {
    arr[k] = leftArr[i];
    i++;
    k++;
  }

  // Copy the remaining elements of rightArr, if any
  while (j < n2) {
    arr[k] = rightArr[j];
    j++;
    k++;
  }
}

// Merge sort function
template <typename T, typename U>
void mergeSort(std::vector<schluesselWertPaar<T, U>> &arr, int left,
               int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    // Sort first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
  }
}

// Binary search function
template <typename T, typename U>
int binarySearch(const std::vector<schluesselWertPaar<T, U>> &arr, int left,
                 int right, T key) {
  if (right >= left) {
    int mid = left + (right - left) / 2;

    // If the key is present at the middle
    if (arr[mid].getSchluessel() == key)
      return mid;

    // If the key is smaller than the middle element, search in the left
    // subarray
    if (arr[mid].getSchluessel() > key)
      return binarySearch(arr, left, mid - 1, key);

    // Otherwise, search in the right subarray
    return binarySearch(arr, mid + 1, right, key);
  }

  // Key not found
  return -1;
}

int main() {
  // Create vector of schluesselWertPaar objects
  std::vector<schluesselWertPaar<int, std::string>> vec = {
      schluesselWertPaar<int, std::string>(1, "one"),
      schluesselWertPaar<int, std::string>(2, "two"),
      schluesselWertPaar<int, std::string>(3, "three"),
      schluesselWertPaar<int, std::string>(4, "four"),
      schluesselWertPaar<int, std::string>(5, "five"),
      schluesselWertPaar<int, std::string>(6, "six"),
      schluesselWertPaar<int, std::string>(7, "seven"),
      schluesselWertPaar<int, std::string>(8, "eight"),
      schluesselWertPaar<int, std::string>(9, "nine"),
      schluesselWertPaar<int, std::string>(10, "ten")};

  // Sort vector
  mergeSort(vec, 0, vec.size() - 1);

  // Print sorted vector
  for (int i = 0; i < static_cast<int>(vec.size()); i++) {
    std::cout << vec[i].getSchluessel() << " " << vec[i].getWert() << std::endl;
  }

  // Search for key 5
  int index = binarySearch(vec, 0, vec.size() - 1, 5);
  if (index != -1) {
    std::cout << "Key found at index " << index << std::endl;
  } else {
    std::cout << "Key not found" << std::endl;
  }

  return 0;
}
