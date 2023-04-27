#include <iostream>

using namespace std;

/*
***********************************************************
Aufgabe 1a)
*/

const int n_inputs = 5; // Wir erstellen eine globale Konstante, um die Anzahl der eingegebenen Zahlen zu steuern.

long min (long inp[n_inputs]) { // Minimumsfunktion: nimmt den Array der eingegebenen Zahlen als Argument
    long smallest = inp[0]; // Die kleinste Zahl wird deklariert und auf die erste Stelle im Array gesetzt
    for (int i = 0; i < n_inputs; i++) { // For-Schleife zählt bis zur Länge des Arrays
        if (inp[i] < smallest) { // Die kleinste Zahl wird auf die aktuelle Stelle im Array gesetzt, falls sie kleiner ist
            smallest = inp[i];
        }
    }
    return smallest;
}

long max (long inp[n_inputs]) { // Maximumsfunktion: Funktioniert analog zu min
    long largest = inp[0];
    for (int i = 0; i < n_inputs; i++) {
        if (inp[i] > largest) {
            largest = inp[i];
        }
    }
    return largest;
}

/*
***********************************************************
Aufgabe 1b)
*/

long avg (long inp[], int n) { // Mittelwertsfunktion: Nimmt wieder die Inputvariable als Argument
    long sum = 0; // Die Summe wird auf 0 initialisiert
    for (int i = 0; i < n; i++) {sum += inp[i];} // Es wird aufsummiert
    return (sum/n); // Ausgegeben wird die Summe geteilt durch die Länge der Inputvariable
}

// Aufgabe 1c innerhalb von main() bearbeitet
int main() {

    long inputs[n_inputs]; // Der Inputarray wird initialisiert mit Länge der Konstante (oben deklariert)
    bool abgebrochen = false; // Zu Aufgabe 1c: Falls abgebrochen wird, sollen min und max übersprungen werden
    long current_input;

    cout << "Gleich wird " << n_inputs << " Mal eine Zahl abgefragt." << endl;

    for (int i = 0; i < n_inputs; i++) { // For-Schleife: Es wird bis zur Länge des Arrays gezählt
        cout << "Bitte gebe die " << (i+1) << ". Zahl ein: "; // Aufforderung zur Eingabe
        cin >> current_input; // Eingabe des i-ten Elements
        if (current_input == 9999) { // (Aufgabe 1c): Überprüfe, ob Abbruchsbedingung eintritt, falls ja, berechne Mittelwert der bisherigen Inputs
            abgebrochen = true;
            cout << "Der Mittelwert beträgt: " << avg(inputs, i) << endl; // avg Funktion wird angewendet
            break;
        }
        inputs[i] = current_input;
    }
    if (abgebrochen == false) { // Wenn Abbruchsbedingung nicht eintrat, gebe Minimum, Maxmimum, sowie Mittelwert aus.
        cout << "Das Minimum beträgt: " << min(inputs) << endl;
        cout << "Das Maximum beträgt: " << max(inputs) << endl;
        cout << "Der Mittelwert beträgt: " << avg(inputs, n_inputs) << endl;
    }
}