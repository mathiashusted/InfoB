#include <iostream>

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