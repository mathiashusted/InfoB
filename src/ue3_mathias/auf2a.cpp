// Gruppe M. Husted, A. Malze, S. Kutscher
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


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
    string input;
    cout << "Bitte gebe einen String ein: ";
    cin >> input;

    vector<pair<char, int>> input_hist = histogram(input);
    for(size_t i = 0; i < input_hist.size(); i++) {
        cout << input_hist[i].first << ", " << input_hist[i].second << endl;
    }
}