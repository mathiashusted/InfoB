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

void mergeSortSWP(std::vector<schluesselWertPaar<int, std::string>> swp) {
    std::vector<int> swpvec;
    for (unsigned i = 0; i < swp.size(); i++) {
        swpvec.push_back(swp[i].getKey());
    }
    mergeSort(swpvec);
}

int main() {

}