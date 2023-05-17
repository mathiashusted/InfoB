/* Informatik B - Sommersemester 2023
Vorlesung am 12.05.2023
Katharina Klost

Hilfsfunktionen zum Sortieren, nur zusammen mit der sorting.cpp zu compilieren
*/
#include <iostream>
#include <vector>
#include "hilfsfunktionen.hpp"


namespace hf{

    void gebe_aus(std::vector<int>& vec, unsigned start, unsigned end){
        if(end>vec.size()){
            std::cout << vec.size() << " " << end << std::endl;
            return;
        }
    std::cout << vec[start];
    for(unsigned k=start+1; k<end; k++){
        std::cout << ", " << vec[k];
    }
    std::cout << std::endl;
}

    void swap(std::vector<int>& elems, unsigned i, unsigned j){
        if (i>=elems.size() || j >= elems.size()){
            return;
        }
        int tmp = elems[i];
        elems[i] = elems[j];
        elems[j] = tmp;
    }

    unsigned minimumIndex(std::vector<int>& elems, unsigned start, unsigned end){
        unsigned min = start;
        for(unsigned i = start; i<end; i++){
            if(elems[i] < elems[min]){
                min = i;
            }
        }
        return min;
    }

    std::vector<int> copy(std::vector<int>& elems, unsigned start, unsigned end){
        std::vector<int> returnVec;
        for(unsigned i= start; i<end; i++){
            returnVec.push_back(elems[i]);
        }
    return returnVec;
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
        std::vector<int> array(size);
        for (unsigned i = 0; i < size; i++)
            array[i] = zufall(0, size);
        return array;
    }

}