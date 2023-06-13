/* Informatik B - Sommersemester 2022
Vorlesung am 18.05.
Katharina Klost

Headerdatei für die Hilfsfunktionen zu den Sortieralgorithmen.

*/

#include <iostream>
#include <vector>
#include "hilfsfunktionen.hpp"

namespace hilfsfunktionen {

void gebe_aus(std::vector<std::pair<int,int>>& vec){
    if(vec.size() == 0)return;
    std::cout <<"(" << vec[0].first << ", " << vec[0].second << ")";
    for(unsigned k=1; k<vec.size(); k++){
      std::cout << ", (" << vec[k].first << ", " << vec[k].second << ")" ;
    }
    std::cout << std::endl;
  }


void gebe_aus(std::vector<int>& vec){
  if(vec.size()==0){
    return;
  }
  std::cout << vec[0];
  for(unsigned k=1; k<vec.size(); k++){
    std::cout << ", " << vec[k];
  }
  std::cout << std::endl;
}


std::vector<int> copy(std::vector<int>& elems, unsigned start, unsigned end){
  std::vector<int> returnVec;
  for(unsigned i= start; i<end; i++){
    returnVec.push_back(elems[i]);
  }
  return returnVec;
}

void swap(std::vector<int>& elems, unsigned i, unsigned j){
  if(i>=elems.size()|| j>=elems.size()){
    return;
  }
  int tmp = elems[i];
  elems[i] = elems[j];
  elems[j] = tmp;
}


unsigned minimumIndex(std::vector<int>& elems, unsigned start, unsigned end){
  unsigned min = start;
  for(unsigned i = start; i < end; i++){
    if(elems[i]<elems[min]){
      min = i;
    }
  }
  return min;
}

bool generator_started = false;
int zufall(int left, int right) {
	// Vor der ersten Zufallszahl muss der Zufallsgenerator gestartet werden.
	if (!generator_started) {
		srandom(time(NULL));
		generator_started = true;
	}
	return left + random() % (right-left);
}

std::vector<int> sortiertes_array(unsigned size, bool aufsteigend) {
	std::vector<int> array(size);
	for (unsigned i = 0; i < size; i++)
		array[i] = aufsteigend * i + (!aufsteigend) * (size - i - 1);
	return array;
}

std::vector<int> zufalls_array(unsigned size) {
	std::vector<int> array = sortiertes_array(size, true);

	for (unsigned i = 0; i < size; i++){
    unsigned swapindex = zufall(0,i);
    int tmp = array[swapindex];
    array[swapindex] = array[i];
		array[i] = tmp;
  }
	return array;
}


}
