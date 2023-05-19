/*
Code von gromdimon
19.05.2023
*/

//**********************************************************************************************
// AUFGABE 1

// a) Wieso lässt sich mittels Binärsuche das Element 10 Nicht in der
// Liste {1, 10, 19, 12, 30, 2, 1, 79} finden? Wendet einen anderen
// Suchalgorithmus aus der Vorlesung an, um das Suchproblem zu
// lösen.
// b) Sucht in der Liste {1, 7, 10, 16, 25, 25, 31, 42, 100} mit Hilfe der
// Binärsuche das Element 7. Aus der von euch gewählten
// Darstellung sollten die einzelnen Vergleiche, sowie deren
// Reihenfolge klar hervorgehen.

#include <iostream>
using namespace std;

// a)
// Binärsuche funktioniert nur bei sortierten Listen
// Alternative kann sein: Zuerst sortieren, dann suchen
// Oder Brute-Force durch die ganze Liste gehen und Elementen vergleichen

// b)
// 1. 25 > 7
// 2. 10 > 7
// 3. 7 = 7
// 4. Liefer 7!

int main() { return 0; }