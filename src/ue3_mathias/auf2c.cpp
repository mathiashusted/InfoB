// Gruppe M. Husted, A. Malze, S. Kutscher
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>

using namespace std;

// Kommentare der Funktionen analog zu 2a)
void deleteLetter(string &input, char x) {
    for (size_t i = 0; i < input.length();) {
        if (input[i] == x) input.erase(i,1);
        else i++;
    }
}


pair<char,int> countPairs(string &input, char search) {
    int count = 0;
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == search) {
            count ++;
        }
    }
    return make_pair(search, count);
}


vector<pair<char, int>> histogram(string input) {
    vector<pair<char,int>> hist;
    pair<char,int> current;
    while (input != "") {
        current = countPairs(input, input[0]);
        deleteLetter(input,input[0]);
        hist.push_back(current);
    }
    return hist;
}

int main() {
    ifstream moby ("moby.txt"); // moby wird geöffnet
    string line;
    if (moby.is_open()) { // Wird false, falls die Datei nicht vorher existiert
        getline(moby, line); // Datei wird gelesen und dem String zugewiesen
        moby.close(); // wird geschlossen
    }
    
    vector<pair<char, int>> input_hist = histogram(line); // String der Datei wird normal weiterverarbeitet
    for(size_t i = 0; i < input_hist.size(); i++) {
        cout << input_hist[i].first << ", " << input_hist[i].second << endl;
    }
}