// Gruppe M. Husted, A. Malze, S. Kutscher

#include <iostream>
#include <vector>

struct Item {
    int weight;
    int value;
};

// Vor: Keine
// Erg: Den Inputvektor ohne dem ersten Element
// Eff: Der Inputvektor ohne dem ersten Element wird ausgegeben
std::vector<Item> eraseFirst(std::vector<Item> input) {
    input.erase(input.begin()); // Erstes Element wird entfernt
    return input;
}

// Vor: Keine
// Erg: Das aufsummierte Gewicht des Inputvektors mit Typ Item
// Eff: Gibt das Gewicht aus
int sumWeight(std::vector<Item> input) {
    int sum = 0;
    for (size_t i = 0; i < input.size(); i++) {
        sum += input[i].weight;
    }
    return sum;
}

// Vor: Keine
// Erg: Vektor der optimalen Verteilung der Gegenstände im Rucksack
// Eff: Gibt den optimalen Vektor aus.
std::vector<Item> optimalItems (std::vector<Item> input, int maxWeight) {
    std::vector<Item> takeFirst; // takeFirst, dropFirst müssen nun Vektoren sein
    std::vector<Item> dropFirst;
    if (input.size() == 0) return {}; // Gebe leeren Vektor aus
    if (input[0].weight <= maxWeight) {
        std::vector<Item> a; // a, b als Zwischenspeicher
        std::vector<Item> b;
        a.push_back(input[0]); // Wir fangen mit dem ersten Gegenstand an, da wir wissen, dass er passt
        b = optimalItems(eraseFirst(input), (maxWeight - input[0].weight)); // Rekursiver Aufruf (erster Gegenstand wird entfernt)
        a.insert(a.end(), b.begin(), b.end()); // Anstatt bloß aufzuaddieren, müssen wir nun auf zwei Vektoren insert anwenden
        takeFirst = a;
    }
        
        //takeFirst = input[0].weight + rucksackRecursive(eraseFirst(input), (maxWeight - input[0].weight));

    // dropFirst wird als rekursiver Aufruf der Funktion initialisiert 
    dropFirst = optimalItems(eraseFirst(input), maxWeight);

    // Gebe das größte Element aus
    return (sumWeight(takeFirst) < sumWeight(dropFirst)) ? dropFirst : takeFirst;
}

int main() {
    Item i1 = {.weight = 2, .value = 5};
    Item i2 = {.weight = 7, .value = 1};
    Item i3 = {.weight = 3, .value = 6};
    Item i4 = {.weight = 3, .value = 2};
    Item i5 = {.weight = 2, .value = 4};
    Item i6 = {.weight = 5, .value = 11};
    std::vector<Item> ex = {i1, i2, i3, i4, i5, i6};
    int maxWeight = 13;
    std::cout << "Gegenstände im Rucksack:\n";
    for (size_t i = 0; i < ex.size(); i++) {
        std::cout << "Gegenstand " << i << " hat den Wert " << ex[i].value << " und das Gewicht " << ex[i].weight << std::endl;
    }
    std::cout << "\n\nOptimale Verteilung der Gegenstände im Rucksack bei Maximalgewicht von " << maxWeight << ":\n";
    std::vector<Item> exOptimal = optimalItems(ex, maxWeight);
    for (size_t i = 0; i < exOptimal.size(); i++) {
        std::cout << "Gegenstand " << i << " mit Wert " << exOptimal[i].value << " mit Gewicht " << exOptimal[i].weight << std::endl;
    }
}