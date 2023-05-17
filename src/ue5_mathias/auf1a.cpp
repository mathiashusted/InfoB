// Namen:
// Tutorium:
// Übung 4, Aufgabe 1
// Kompilieren: g++ -std=c++14 -Wall -Wextra -Werror -pedantic -o ultrasort hilfsfunktionen.cpp ultrasort.cpp
// Denken Sie daran, die Datei entsprechend des Namensschemas zu benennen
// Denken Sie an die Spezifikationen der Funktionen.

#include "hilfsfunktionen.hpp"
#include <iostream>
#include <vector>


/*
*******************************
Insertionsort
*/


void insertionsort(std::vector<int>& l) {
    int current, j;
    for (size_t i = 1; i < l.size(); i++) {
        current = l[i];
        j = i-1;

        while (j >= 0 && current < l[j]) {
            l[j+1] = l[j];
            j -= 1;
        }
        
        l[j+1] = current;
    }
}



/*
*******************************
Mergesort (wie in der VL)
*/

void merge(std::vector<int>& elems, unsigned begin, unsigned mid, unsigned end){
    std::vector<int> firstHalf = hf::copy(elems, begin, mid);
    std::vector<int> secondHalf = hf::copy(elems, mid, end);
    unsigned i = 0;
    unsigned j = 0;
    while(begin + i + j < end){
        if ( j >= secondHalf.size() || ((i<firstHalf.size()) && (firstHalf[i]<secondHalf[j]))){
            elems[begin+i+j] = firstHalf[i];
            i++;
        }else{
            elems[begin+i+j] = secondHalf[j];
            j++;
        }
    }
}

void mergeSortHelp(std::vector<int>& elems, unsigned start, unsigned end){
    if(start==end||start==end-1){
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

/*
*******************************
Ultrasort
*/

std::vector<int> mergeUltra(std::vector<int>& l, std::vector<int>& r) {
    std::vector<int> output;
    unsigned i = 0, j = 0; // Zwei Zählervariablen für jede Liste

    while (i < l.size() && j < r.size()) {
        std::cout << "Status i: " << l[i] << "\nStatus j: " << r[j] << "\n\n";
        if (l[i] < r[j]) {
            output.push_back(l[i]);
            i++;
        }
        else if (l[i] >= r[j]) {
            output.push_back(r[j]);
            j++;
        }
        else {
            if (i < l.size()) {
                output.push_back(l[i]);
                i++;
            }
            if (j < r.size()) {
                output.push_back(r[j]);
                j++;
            }
        }
    }
    std::cout << "\nFertig iteriert! Das Ergebnis lautet:\n";
    for (size_t i = 0; i < output.size(); i++) {
        std::cout << output[i] << std::endl;
    }
    return output;
}

void ultraSort(std::vector<int>& elems) {
    std::cout << "Rekursiver Aufruf UltraSort\n";
    for (size_t i = 0; i < elems.size(); i++) {
        std::cout << elems[i] << std::endl;
    }

    if (elems.size() <= 1) return;
    unsigned third = elems.size() / 3;
    std::vector<int> l, r;
    l = hf::copy(elems, 0, third);
    r = hf::copy(elems, third + 1, elems.size());
    ultraSort(elems);
    ultraSort(elems);
}

void ultraSortParam(std::vector<int>& elems, float fraction) {
    if (elems.empty() && fraction) {

    }
}

/// Main ----------------------------------------------------------------
// Auch die Main muss noch angepasst werden.
// Denken Sie nicht nur an das Zeitmessen sondern auch daran, zu überprüfen
// ob ihr Algorithmus wirklich das tut, was er tun soll - sortieren!
//
// Passen Sie die main dahingehend an, dass auch die parametrisierte Variante
// von ultraSort getestet wird

void test() {
    std::vector<int> array = hf::zufalls_array(10);
    ultraSort(array);
    std::cout << "\n\nOutput:\n";
    for (size_t i = 0; i < array.size(); i++) {
        std::cout << array[i] << std::endl;
    }
}

int main() {
	srand(time(NULL)); // Zufallsgenerator starten. Technische Notwendigkeit.
	//double time;
	//std::vector<int> array;
	/*for (int size = 10000; size <= 10000000; size *= 10) {
		std::cout << "   " << size << " Elemente:" << std::endl;

		// Zufälliges Array testen:
		array = hf::zufalls_array(size);

		time = clock(); // Startzeit
		ultraSort(array);
		time = clock() - time; // Endzeit

		std::cout << "      Zufällig: " << (time/CLOCKS_PER_SEC) << " Sekunden" << std::endl;

		// Aufsteigend sortiertes Array testen:
		array = hf::sortiertes_array(size, true);

		time = clock(); // Startzeit
		ultraSort(array);
		time = clock() - time; // Endzeit

		std::cout << "      Aufsteigend: " << (time/CLOCKS_PER_SEC) << " Sekunden" << std::endl;

		// Absteigend sortiertes Array testen:
		array = hf::sortiertes_array(size, false);

		time = clock(); // Startzeit
		ultraSort(array);
		time = clock() - time; // Endzeit

		std::cout << "      Absteigend: " << (time/CLOCKS_PER_SEC) << " Sekunden" << std::endl;
	}*/
    test();
	return 0;
}


