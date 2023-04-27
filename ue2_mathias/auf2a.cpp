#include <iostream>

//2a) Schreiben Sie ein Programm, das eine Zahl von der Konsole liest und die Quersumme einer Zahl
//berechnet. Verwenden Sie einmal eine for und einmal eine while Schleife.

using namespace std;

int quersumme(int input) {
    int inp = input;
    int sum = 0;
    while (inp/10 || inp%10) { // While-Schleife: Solange inp modulo 10 nicht gleich false (0) (oder inp/10) ist, mache weiter
        sum += inp % 10; // Der Quersumme addieren wir unser aktuelles Ziffer (ermittelt mit Modulo)
        inp /= 10; // inp wird durch 10 geteilt
    }
    return sum; // Gesamtsumme als Rückgabewert
} 

int main() {
    for (int input; input != 9999;) { // Wir verwenden eine For-Schleife, inkrementieren allerdings nicht die Variable, sondern hören erst bei einer Eingabe von 9999 auf (wie in der ersten Aufgabe)
        cout << "Bitte gebe eine Zahl ein: ";
        cin >> input;
        if (input == 9999) break;
        else cout << "Die Quersumme beträgt " << quersumme(input) << endl;
    }
}