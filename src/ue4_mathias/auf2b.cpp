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
// Erg: Optimaler Wert des Rucksackproblems (wie aus der VL)
// Eff: Optimaler Wert wird ausgegeben
int rucksackRecursive(std::vector<Item> input, int maxWeight) {
    int takeFirst = 0;
    int dropFirst = 0;
    if (input.size() == 0) return 0;
    // Wenn g1 <= Rucksackskapazität (= es gibt noch Platz) erfolgt der rekursive Aufruf auf takeFirst
    if (input[0].weight <= maxWeight)
        takeFirst = input[0].value + rucksackRecursive(eraseFirst(input), (maxWeight - input[0].weight)); // Wert wird zum rek. Aufruf dazuaddiert
    else takeFirst = 0;

    // dropFirst wird als rekursiver Aufruf der Funktion initialisiert 
    dropFirst = rucksackRecursive(eraseFirst(input), maxWeight);

    // Gebe das größte Element aus
    return (takeFirst < dropFirst) ? dropFirst : takeFirst;
}

int main() {
    Item i1 = {.weight = 2, .value = 5};
    Item i2 = {.weight = 7, .value = 1};
    Item i3 = {.weight = 3, .value = 6};
    Item i4 = {.weight = 3, .value = 2};
    Item i5 = {.weight = 2, .value = 4};
    Item i6 = {.weight = 5, .value = 11};
    std::vector<Item> ex = {i1, i2, i3, i4, i5, i6};
    int maxWeight = 5;
    std::cout << "Gegenstände im Rucksack:\n";
    for (size_t i = 0; i < ex.size(); i++) {
        std::cout << "Gegenstand " << i << " hat den Wert " << ex[i].value << " und das Gewicht " << ex[i].weight << std::endl;
    }
    std::cout << "Optimaler Wert bei Maximalgewicht von " << maxWeight << ": " << rucksackRecursive(ex, maxWeight) << std::endl;
}