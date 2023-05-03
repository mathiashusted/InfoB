// Gruppe M. Husted, A. Malze, S. Kutscher
#include <iostream>

using namespace std;

int main() {
    int n_inputs; // Diesmal wird n_inputs erst mit der Eingabe initialisiert
    cout << "Wie viele Eingaben willst du machen?: ";
    cin >> n_inputs;
    // (Rest des Programms ist analog zu auf1a)
    int smallest, largest, input;

    cout << "Bitte gebe eine Zahl ein: ";
    cin >> input;

    smallest = largest = input;

    for (int i = 0; i < (n_inputs-1); i++) { 
        cout << "Bitte gebe eine Zahl ein: ";
        cin >> input;
        if (input < smallest) smallest = input;
        if (input > largest)  largest = input;

    }

    cout << "Die größte Zahl beträgt " << largest << endl; // Ausgaben
    cout << "Die kleinste Zahl beträgt " << smallest << endl;
}