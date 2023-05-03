// Gruppe M. Husted, A. Malze, S. Kutscher
#include <iostream>

using namespace std;

int main() {
    int n_inputs = 5; // Anzahl der Inputs
    int smallest, largest, input; // Die benötigten Integers
    
    cout << "Bitte gebe eine Zahl ein: ";  // Zur Eingabe aufgefordert.
    cin >> input;

    smallest = largest = input; // Initialisiere Werte von smallest, largest

    for (int i = 0; i < (n_inputs-1); i++) { // Beginn der For-Schleife
        cout << "Bitte gebe eine Zahl ein: ";
        cin >> input;
        if (input < smallest) smallest = input; // Falls der eingegebene Wert kleiner ist als die kleinste Zahl, aktualisiere
        if (input > largest)  largest = input;  // Analog
    }

    cout << "Die größte Zahl beträgt " << largest << endl; // Ausgabe
    cout << "Die kleinste Zahl beträgt " << smallest << endl;
}