/*
Code von gromdimon
02.06.2023
*/

//**********************************************************************************************
// AUFGABE 2c

#include <iostream>
using namespace std;

// Betrachten Sie die folgende Funktion. Schreiben Sie eine Spezifizierung für
// die Funktion. Verwendet die Funktion Call-by-Reference oder Call-by-Value?
// Begründen Sie Ihre Antwort.

// Call-by-Value, da der Pointer kopiert wird und somit die Variable nicht
// verändert wird. Eingabe: pointer auf int Ausgabe: keine Effekt: Wert der
// Variable wird um 1 erhöht
void increase(int *aptr) { (*aptr)++; }

int main() { return 0; }