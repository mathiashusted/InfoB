// Gruppe M. Husted, A. Malze, S. Kutscher

#include <iostream>
#include <string>
#include <vector>
#include "hilfsfunktionen.hpp"
#include "hilfsfunktionen.cpp"

template <typename K, typename V> class schluesselWertPaar {
    private:
        K key;
        V value;
    public:
        // Vor:
        // Erg:
        // Eff: Erstellt neue Instanz von schluesselWertPaar
        schluesselWertPaar(const K & argKey, const V & argValue) {
            this -> key = argKey;
            this -> value = argValue;
        }
        // Vor:
        // Erg: True, falls Key von this -> key < argPaar.key, sonst false
        // Eff:
        bool operator<(const schluesselWertPaar & argPaar) {
            return (this -> key < argPaar.key);
        }
        // Erg: Key von this
        K getKey() {
            return this -> key;
        }
        // Erg: Value von this
        V getValue() {
            return this -> value;
        }
        // Eff: Key von this wird auf den Key von argKey gesetzt
        void setKey(const K & argKey) {
            this -> key = argKey;
        }
        // Eff: Value von this wird auf Value von argValue gesetzt
        void setValue(const V & argValue) {
            this -> value = argValue;
        }
};






void merge(std::vector<int>& elems, unsigned start, unsigned mid, unsigned end){
  std::vector<int> firstHalf = hilfsfunktionen::copy(elems, start, mid);
  std::vector<int> secondHalf = hilfsfunktionen::copy(elems, mid, end);
  unsigned i = 0;
  unsigned j = 0;
  while(start+ i+j<end){
    // //Alternative Abfrage im if,führt zu weniger redundatem Code
    // if (j>=secondHalf.size() || ((i<firstHalf.size() && firstHalf[i]<=secondHalf[j]))){
    //     elems[start+i+j]=firstHalf[i];
    //     i++;
    //   }
    //   else{
    //     elems[start+i+j]=secondHalf[j];
    //     j++;
    //   }

    if(j>=secondHalf.size()){
      elems[start+i+j] = firstHalf[i];
      i++;
      continue;
    }
    else if(i>=firstHalf.size()){
      elems[start+i+j] = secondHalf[j];
      j++;
      continue;
    }
    else if(firstHalf[i]<=secondHalf[j]){
      elems[start+i+j] = firstHalf[i];
      i++;
      continue;
    }else{
      elems[start+i+j] = secondHalf[j];
      j++;
      continue;
    }
  }
}

void mergeSortHelp(std::vector<int>& elems, unsigned start, unsigned end){
  if(start==end || start==end-1){
    return;
  }
  unsigned mid = (start+end)/2;
  mergeSortHelp(elems, start, mid);
  mergeSortHelp(elems, mid, end);
  merge(elems, start, mid, end);
}

void mergeSort(std::vector<int>& elems){
  mergeSortHelp(elems, 0, elems.size());
}


// Vor:
// Erg: Sortierter Vektor aus Schlüssel-Werte-Paaren, nach Schlüssel sortiert
// Eff: 
std::vector<schluesselWertPaar<int, std::string>> mergeSortSWP(std::vector<schluesselWertPaar<int, std::string>> & swp) {
    std::vector<int> swpvec;
    for (unsigned i = 0; i < swp.size(); i++) {
        swpvec.push_back(swp[i].getKey());
    }
    mergeSort(swpvec);
    std::vector<schluesselWertPaar<int, std::string>> returnVec;
    for (unsigned i = 0; i < swpvec.size(); i++) {
      for (unsigned j = 0; j < swp.size(); j++) {
        if (swpvec[i] == swp[j].getKey()) {
          returnVec.push_back(swp[j]);
          break;
        }
      }
    }
    return returnVec;
}


// 3c) Ausführlicher Test
int main() {
  schluesselWertPaar<float, int> swp(236.2, 6527); // Schlüssel-Werte-Paar mit alternativen Datentypen (Key: Float, Value: Int)
  schluesselWertPaar<float, int> swp2(195.67, 5727);
  std::cout << "swp (float) < swp2: " << (swp < swp2) << "\n"; // Können verglichen werden, auch wenn der Datentyp des Keys nicht int ist
  swp.setKey(571.2);
  std::cout << "Neuer Key von swp: " << swp.getKey() << " mit Value " << swp.getValue() << "\n";
  std::vector<schluesselWertPaar<int, std::string>> test;
  schluesselWertPaar<int, std::string> paar1(3, "Paar 1");
  schluesselWertPaar<int, std::string> paar2(7, "Paar 2");
  schluesselWertPaar<int, std::string> paar3(1, "Paar 3");
  schluesselWertPaar<int, std::string> paar4(11, "Paar 4");
  schluesselWertPaar<int, std::string> paar5(9, "Paar 5");
  test.push_back(paar1);
  test.push_back(paar2);
  test.push_back(paar3);
  test.push_back(paar4);
  test.push_back(paar5);
  std::vector<schluesselWertPaar<int, std::string>> testSorted = mergeSortSWP(test); // Wird aufsteigend sortiert
  for (unsigned i = 0; i < testSorted.size(); i++) {
    std::cout << i << "-tes Element: " << testSorted[i].getKey() << ", " << testSorted[i].getValue() << "\n";
  }
}