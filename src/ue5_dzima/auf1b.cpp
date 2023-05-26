/*
Code von gromdimon
17.05.2023
*/

//**********************************************************************************************
// AUFGABE 1a

#include <iostream>
#include <limits>
#include <vector>

namespace hf {

void gebe_aus(std::vector<int> &vec, unsigned start, unsigned end) {
  if (end > vec.size()) {
    std::cout << vec.size() << " " << end << std::endl;
    return;
  }
  std::cout << vec[start];
  for (unsigned k = start + 1; k < end; k++) {
    std::cout << ", " << vec[k];
  }
  std::cout << std::endl;
}

void swap(std::vector<int> &elems, unsigned i, unsigned j) {
  if (i >= elems.size() || j >= elems.size()) {
    return;
  }
  int tmp = elems[i];
  elems[i] = elems[j];
  elems[j] = tmp;
}

unsigned minimumIndex(std::vector<int> &elems, unsigned start, unsigned end) {
  unsigned min = start;
  for (unsigned i = start; i < end; i++) {
    if (elems[i] < elems[min]) {
      min = i;
    }
  }
  return min;
}

std::vector<int> copy(std::vector<int> &elems, unsigned start, unsigned end) {
  std::vector<int> returnVec;
  for (unsigned i = start; i < end; i++) {
    returnVec.push_back(elems[i]);
  }
  return returnVec;
}

bool generator_started = false;
int zufall(int left, int right) {
  // Vor der ersten Zufallszahl muss der Zufallsgenerator gestartet
  if (!generator_started) {
    srandom(time(NULL));
    generator_started = true;
  }
  return left + random() % (right - left);
}

std::vector<int> sortiertes_array(unsigned size, bool aufsteigend) {
  std::vector<int> array(size);
  for (unsigned i = 0; i < size; i++)
    array[i] = aufsteigend * i + (!aufsteigend) * (size - i - 1);
  return array;
}

std::vector<int> zufalls_array(unsigned size) {
  std::vector<int> array(size);
  for (unsigned i = 0; i < size; i++)
    array[i] = zufall(0, size);
  return array;
}

} // namespace hf

// Voraussetzung: elementen vector, start und end
// Effekt: Teil des Vektors von start bis end wird sortiert
void insertSort(std::vector<int> &elems, int start, int end) {
  for (int i = start + 1; i < end; i++) {
    int j = i;
    while (j > start && elems[j] < elems[j - 1]) {
      std::swap(elems[j], elems[j - 1]);
      j--;
    }
  }
}

// Voraussetzung: elementen vector, begin, mid und end
// Effekt: Teil des Vektors von begin bis end wird sortiert
void merge(std::vector<int> &elems, unsigned begin, unsigned mid,
           unsigned end) {
  std::vector<int> firstHalf = hf::copy(elems, begin, mid);
  std::vector<int> secondHalf = hf::copy(elems, mid, end);
  unsigned i = 0;
  unsigned j = 0;
  while (begin + i + j < end) {
    if (j >= secondHalf.size() ||
        ((i < firstHalf.size()) && (firstHalf[i] < secondHalf[j]))) {
      elems[begin + i + j] = firstHalf[i];
      i++;
    } else {
      elems[begin + i + j] = secondHalf[j];
      j++;
    }
  }
}

// Voraussetzung: elementen vector, begin und end, splitRatio - split ratio in
// the range of 1-99 Effekt: elementen vector wird sortiert
void ultraSortHelp(std::vector<int> &elems, int begin, int end,
                   int splitRatio) {
  // Wenn der zu sortierende Teil des Vektors kleiner als 2 ist, ist er bereits
  // sortiert
  if (end - begin < 2) {
    return;
  }
  if (end - begin == 2) {
    if (elems[begin] > elems[begin + 1]) {
      std::swap(elems[begin], elems[begin + 1]);
    }
    return;
  }
  int mid = begin + (end - begin) * splitRatio / 100;
  // Rekursiver Aufruf von insertSort
  insertSort(elems, begin, mid);
  // Rekursiver Aufruf von ultraSort
  ultraSortHelp(elems, begin + mid, end, splitRatio);
  // Final merge
  merge(elems, begin, begin + mid, end);
}

// Voraussetzung: elementen vector, startSplitRatio, endSplitRatio, stepSize
// Effekt: Find the optimal split ratio based on execution time
int findOptimalSplitRatio(std::vector<int> &elems, int startSplitRatio,
                          int endSplitRatio, int stepSize) {
  int optimalSplitRatio = startSplitRatio;
  double optimalTime = std::numeric_limits<double>::max();
  for (int splitRatio = startSplitRatio; splitRatio <= endSplitRatio;
       splitRatio += stepSize) {
    std::vector<int> copy =
        elems;             // Create a copy of the vector for each split ratio
    double time = clock(); // Startzeit
    ultraSortHelp(copy, 0, copy.size(), splitRatio);
    time = clock() - time; // Endzeit
    if (time < optimalTime) {
      optimalTime = time;
      optimalSplitRatio = splitRatio;
    }
  }
  return optimalSplitRatio;
}

/// Main ----------------------------------------------------------------
int main() {
  srand(time(NULL)); // Zufallsgenerator starten. Technische Notwendigkeit.
  double time;
  std::vector<int> array;
  for (int size = 10000; size <= 10000000; size *= 10) {
    std::cout << "   " << size << " Elemente:" << std::endl;

    // Zufälliges Array testen:
    array = hf::zufalls_array(size);

    // Find the optimal split ratio for the current array size
    int optimalSplitRatio = findOptimalSplitRatio(array, 1, 99, 1);

    time = clock(); // Startzeit
    ultraSortHelp(array, 0, array.size(), optimalSplitRatio);
    time = clock() - time; // Endzeit

    std::cout << "      Zufällig (Split Ratio: " << optimalSplitRatio
              << "): " << (time / CLOCKS_PER_SEC) << " Sekunden" << std::endl;

    // Aufsteigend sortiertes Array testen:
    array = hf::sortiertes_array(size, true);

    // Find the optimal split ratio for the current array size
    optimalSplitRatio = findOptimalSplitRatio(array, 1, 99, 1);

    time = clock(); // Startzeit
    ultraSortHelp(array, 0, array.size(), optimalSplitRatio);
    time = clock() - time; // Endzeit

    std::cout << "      Aufsteigend (Split Ratio: " << optimalSplitRatio
              << "): " << (time / CLOCKS_PER_SEC) << " Sekunden" << std::endl;

    // Absteigend sortiertes Array testen:
    array = hf::sortiertes_array(size, false);

    // Find the optimal split ratio for the current array size
    optimalSplitRatio = findOptimalSplitRatio(array, 1, 99, 1);

    time = clock(); // Startzeit
    ultraSortHelp(array, 0, array.size(), optimalSplitRatio);
    time = clock() - time; // Endzeit

    std::cout << "      Absteigend (Split Ratio: " << optimalSplitRatio
              << "): " << (time / CLOCKS_PER_SEC) << " Sekunden" << std::endl;
  }
  return 0;
}

// Output in terminal:
//
//    10000 Elemente:
//       Zufällig (Split Ratio: 1): 0.001105 Sekunden
//       Aufsteigend (Split Ratio: 41): 0.000247 Sekunden
//       Absteigend (Split Ratio: 1): 0.001187 Sekunden
//    100000 Elemente:
//      Zufällig (Split Ratio: 1): 0.022625 Sekunden
//      Aufsteigend (Split Ratio: 39): 0.002539 Sekunden
//      Absteigend (Split Ratio: 1): 0.035921 Sekunden
