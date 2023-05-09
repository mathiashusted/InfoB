// Gruppe M. Husted, A. Malze, S. Kutscher
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


// Vor: Keine
// Erg: Alle Vorkommen vom char x werden im String gelöscht
void deleteLetter(string &input, char x) {
    for (size_t i = 0; i < input.length();) {
        if (input[i] == x) input.erase(i,1);
        else i++;
    }
}


// Vor: Keine
// Erg: Ein Pair wird ausgegeben, das an erster Stelle den char search enthält, und an zweiter Stelle die Anzahl der Vorkommen von search im String input
pair<char,int> countPairs(string input, char search) {
    int count = 0; // Anzahl der Vorkommen - muss außerhalb der Schleife deklariert werden, um mit ausgegeben werden zu können
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == search) {
            count ++; // Falls char gefunden, inkrementiere
        }
    }
    return make_pair(search, count);
}


// Vor: Keine
// Erg: Ein Vector von Pairs wird ausgegeben, der das Histogramm enthält
// Idee: Aus dem String input werden nach und nach alle chars entfernt, die bereits gezählt wurden. Wenn der String leer ist,
// haben wir den String fertig verarbeitet, und können das Histogramm ausgeben.
vector<pair<char, int>> histogram(string input) {
    vector<pair<char,int>> hist;
    pair<char,int> current; // Die "Laufvariable" für unsere Pairs
    while (input != "") {
        current = countPairs(input, input[0]); // Pair wird erstellt
        deleteLetter(input,input[0]); // Alle Vorkommen werden aus dem String gelöscht
        hist.push_back(current); // Füge zur Ausgabe hinzu, und mache weiter
    }
    return hist;
}

int main() {
    string input;
    cout << "Bitte gebe einen String ein: ";
    cin >> input;

    vector<pair<char, int>> input_hist = histogram(input); // Der Vektor wird anhand der Eingabe erstellt
    for(size_t i = 0; i < input_hist.size(); i++) {
        cout << input_hist[i].first << ", " << input_hist[i].second << endl;
    }
}