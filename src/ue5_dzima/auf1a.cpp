/*
Code von gromdimon
17.05.2023
*/

//**********************************************************************************************
// AUFGABE 1a

#include <iostream>
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
// Effekt: Teil des Vektors von start zum end wird sortiert
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

// Vorraussetzung: elementen vector, begin und end
// Effekt: elementen vector wird sortiert
void ultraSortHelp(std::vector<int> &elems, int begin, int end) {
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
  int mid = (end - begin) / 3;
  // Rekursiver Aufruf von insertSort
  insertSort(elems, begin, begin + mid);
  // Rekursiver Aufruf von ultraSort
  ultraSortHelp(elems, begin + mid, end);
  // Final merge
  merge(elems, begin, begin + mid, end);
}

// Voraussetzung: elementen vector
// Effekt: elementen vector wird sortiert
void ultraSort(std::vector<int> &elems) {
  // Ruft Hilfsfunktion auf
  ultraSortHelp(elems, 0, elems.size());
}

/// Main ----------------------------------------------------------------
// Auch die Main muss noch angepasst werden.
// Denken Sie nicht nur an das Zeitmessen sondern auch daran, zu überprüfen
// ob ihr Algorithmus wirklich das tut, was er tun soll - sortieren!
//
// Passen Sie die main dahingehend an, dass auch die parametrisierte Variante
// von ultraSort getestet wird

int main() {
  srand(time(NULL)); // Zufallsgenerator starten. Technische Notwendigkeit.
  double time;
  std::vector<int> array;
  for (int size = 10000; size <= 10000000; size *= 10) {
    std::cout << "   " << size << " Elemente:" << std::endl;

    // Zufälliges Array testen:
    array = hf::zufalls_array(size);

    time = clock(); // Startzeit
    ultraSort(array);
    time = clock() - time; // Endzeit

    std::cout << "      Zufällig: " << (time / CLOCKS_PER_SEC) << " Sekunden"
              << std::endl;

    // Aufsteigend sortiertes Array testen:
    array = hf::sortiertes_array(size, true);

    time = clock(); // Startzeit
    ultraSort(array);
    time = clock() - time; // Endzeit

    std::cout << "      Aufsteigend: " << (time / CLOCKS_PER_SEC) << " Sekunden"
              << std::endl;

    // Absteigend sortiertes Array testen:
    array = hf::sortiertes_array(size, false);

    time = clock(); // Startzeit
    ultraSort(array);
    time = clock() - time; // Endzeit

    std::cout << "      Absteigend: " << (time / CLOCKS_PER_SEC) << " Sekunden"
              << std::endl;
  }
  return 0;
}

// Output in terminal:
//
//    10000 Elemente:
//       Zufällig: 0.077949 Sekunden
//       Aufsteigend: 0.000488 Sekunden
//       Absteigend: 0.098145 Sekunden
//    100000 Elemente:
//       Zufällig: 4.85988 Sekunden
//       Aufsteigend: 0.005054 Sekunden
//       Absteigend: 9.69859 Sekunden
//    1000000 Elemente:
//       Zufällig: 510.348 Sekunden
//       Aufsteigend: 0.048899 Sekunden
//       Absteigend: 1046.18 Sekunden
//    10000000 Elemente:
//  	 Zufällig: 59382.3 Sekunden
//	     Aufsteigend: 0.524578 Sekunden
