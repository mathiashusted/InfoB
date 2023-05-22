// Gruppe M. Husted, A. Malze, S. Kutscher
#include <iostream>

using namespace std;

int main() {
    int n_inputs; // Diesmal wird n_inputs erst mit der Eingabe initialisiert
    cout << "Wie viele Eingaben willst du machen?: ";
    cin >> n_inputs;
    // (Rest des Programms ist analog zu auf1a)
    int smallest, largest, input, sum; // Wir brauchen eine Zusatzvariable sum, um ständig aufzusummieren
    bool abgebrochen = false; // Wir initialisieren eine Variable, um zu prüfen, ob die Abbruchbedingung eingetreten ist
    cout << "Bitte gebe eine Zahl ein: ";
    cin >> input;
    smallest = largest = input;
    for (int i = 0; i < (n_inputs-1); i++) { 
        cout << "Bitte gebe eine Zahl ein: ";
        cin >> input;
        if (input == 9999) {
            cout << "Abgebrochen! Der Mittelwert beträgt " << (sum/(i+1)) << endl; // Wenn abgebrochen wird, geben wir den Mittelwert aus
            abgebrochen = true; // Wir setzen abgebrochen auf true, damit nach der Schleife nicht die größte und kleinste Zahl ausgegeben werden
            break;
        } else {
            if (input < smallest) smallest = input;
            if (input > largest)  largest = input;
            sum += input; // Es werden die Inputs aufsummiert für den Fall, dass abgebrochen wird. (Dann muss der Mittelwert berechnet werden)
        }

    }

    // Nur wenn nicht mit 9999 abgebrochen wurde, wird der Mittelwert ausgegeben
    if (!abgebrochen)cout << "Die größte Zahl beträgt " << largest << "\nDie kleinste Zahl beträgt " << smallest << endl;
}