// Namen:
// Tutorium:
// Übung 4, Aufgabe 1
// Kompilieren: g++ -std=c++14 -Wall -Wextra -Werror -pedantic -o ultrasort hilfsfunktionen.cpp ultrasort.cpp
// Denken Sie daran, die Datei entsprechend des Namensschemas zu benennen
// Denken Sie an die Spezifikationen der Funktionen.

#include "hilfsfunktionen.hpp"
#include <iostream>
#include <vector>


void ultraSort(std::vector<int> elems);

void ultraSortParam(std::vector<int> elems, float fraction);


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
	}
	return 0;
}
