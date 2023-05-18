/*
Gruppe M. Husted, A. Malze, S. Kutscher

Wir habe in der Vorlesung eine Möglichkeit kennengelernt das Minimum einer Liste zu bestimmen. In
dieser Aufgabe geht es um eine alternative Möglichkeit dafür.
Es soll ein Turniermodus betrachtet werden. Dazu werden in der ersten Runde, immer zwei benachbarte
Zahlen miteinander verglichen. Die kleinere „gewinnt“ und kommt in die nächste Runde. In dieser Art
und Weise werden die Zahlen weiter verglichen, bis nach der letzten Runde nur noch eine Zahl übrig
ist.

*/

#include <iostream>
#include <vector>


// Vor: Keine
// Erg: Keins
// Eff: Entfernt i-tes Element aus dem Vektor
void removeElem(std::vector<int> & input, size_t index) {
    if (index >= input.size()-1) {
        input.pop_back();
        return;
    }
    for (size_t i = index; i < input.size()-1; i++)
        input[i] = input[i+1];
    input.pop_back();
}

// Vor: Keine
// Erg: Den minimalen Wert von input
// Eff: Keine
int turnierMin(std::vector<int> & input) {
    if (input.empty()) return 0;

    std::vector<int> candidates = input;
    while (candidates.size() > 1) {
        for (size_t i = 0; i < (candidates.size() - 1); i++) {
            if (candidates[i] < candidates[i+1]) removeElem(candidates, (i+1));
            else removeElem(candidates, i);
        }
    }
    return candidates[0];
}


int main() {
    std::vector<int> array = {6,23,98,55,22,(-1), (-3298), 32, (-4444), (-5248), 3, 2938, 38};
    std::cout << "Minimum des Arrays beträgt " << turnierMin(array) << std::endl;
}