// Gruppe M. Husted, A. Malze, S. Kutscher
#include <iostream>
/* 2b)
Schreiben Sie ein Programm, welches für alle Zahlen von 0 bis zu einer vom Nutzer eingegebenen
Schranke für jede Zahl, die nur durch 3 teilbar ist bli, für jede Zahl, die durch nur 5 teilbar ist
bla und für jede Zahl, die nur durch 7 teilbar ist blub ausgibt. Ist eine Zahl nur durch 3 und
5 teilbar, soll blibla, ist sie nur durch 3 und 7 teilbar bliblub und ist sie nur durch 5 und 7
teilbar blablub ausgegeben werden. Wenn die Zahl durch 3, 5 und 7 teilbar ist soll bliblablub
ausgegeben werden. Die Ausgabe soll jeweils in einer eigenen Zeile passieren.
*/
using namespace std;

int main() {
    int input;
    cout << "Gebe eine Zahl ein: ";
    cin >> input;

    for (int i = 0; i <= input; i++) { // i läuft bis zum eingegebenen Wert
        if (i % 3 == 0 && i % 5 != 0 && i % 7 != 0) // i ist durch 3, aber nicht 5 und nicht 7 teilbar (für andere Fälle analog)
            cout << "bli" << endl;
        else if (i % 3 != 0 && i % 5 == 0 && i % 7 != 0)
            cout << "bla" << endl;
        else if (i % 3 != 0 && i % 5 != 0 && i % 7 == 0)
            cout << "blub" << endl;
        else if (i % 3 == 0 && i % 5 == 0 && i % 7 != 0)
            cout << "blibla" << endl;
        else if (i % 3 == 0 && i % 5 != 0 && i % 7 == 0)
            cout << "bliblub" << endl;
        else if (i % 3 != 0 && i % 5 == 0 && i % 7 == 0)
            cout << "blablub" << endl;
        else if (i % 3 == 0 && i % 5 == 0 && i % 7 == 0)
            cout << "bliblablub" << endl;
    }
}