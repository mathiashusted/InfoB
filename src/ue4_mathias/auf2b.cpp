// Gruppe M. Husted, A. Malze, S. Kutscher

#include <iostream>
#include <vector>

struct Item {
    int weight;
    int value;
};

std::vector<Item> eraseFirst(std::vector<Item> input) {
    input.erase(input.begin());
    return input;
}

int rucksackRecursive(std::vector<Item> input, int maxWeight) {
    int takeFirst = 0;
    int dropFirst = 0;
    if (input.size() == 0) return 0;
    if (input[0].weight <= maxWeight)
        takeFirst = input[0].weight + rucksackRecursive(eraseFirst(input), (maxWeight - input[0].weight));
    else takeFirst = 0;

    dropFirst = rucksackRecursive(eraseFirst(input), maxWeight);

    return (takeFirst < dropFirst) ? dropFirst : takeFirst;
}

int main() {
    Item i1 = {.weight = 1, .value = 2};
    Item i2 = {.weight = 2, .value = 3};
    Item i3 = {.weight = 3, .value = 4};
    Item i4 = {.weight = 4, .value = 5};
    std::vector<Item> ex = {i1, i2, i3, i4};
    std::cout << "Ergebnis: " << rucksackRecursive(ex, 5) << std::endl;
}