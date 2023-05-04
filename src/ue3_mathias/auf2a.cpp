#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

pair<char,int> countPairs(string input, char search) {
    int count = 0;
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == search) {
            count ++;
        }
    }
    return make_pair(search, count);
}

string deleteLetter(string input, char x) {
    string output = input;
    for (size_t i = 0; i <= input.length(); i++) {
        if (i <= output.length())
            if (output[i] == x) output.erase(i,1);
    }
    return output;
}
/*
vector<pair<char, int>> histogram(string input) {
    pair<char, int> test (input[0], 2);
    vector<char> hist_char;
    vector<int> hist_int;
    for (size_t vec_loop = 0; vec_loop < input.length(); vec_loop++) {

    }
    vector<pair<char,int>> hist;
    for (size_t vec_loop = 0; vec_loop < input.length(); vec_loop++) {
        if (find(hist.begin(), hist.end(), input[vec_loop]) != hist.end()) {

        }
        hist.push_back({input[vec_loop], 1});
    }
    return hist;
}
*/
int main() {
    string input;
    cout << "Bitte gebe einen String ein: ";
    cin >> input;
    cout << countPairs(input, 'a').first << ", " << countPairs(input, 'a').second << endl;
    cout << deleteLetter(input,'a');
}