#include <iostream>
#include <vector>

// Implementation of binary search

bool binarySearch(std::vector<int> & input, int search, unsigned begin, unsigned end) {
    unsigned middle = (begin+end)/2;
    if (begin >= end) return false;

    if (input[middle] == search) return true;
    else if (input[middle] > search){
        return binarySearch(input, search, begin, middle);
    }
    else {
        return binarySearch(input, search, middle + 1, end);
    }
}

int main() {
    unsigned search;
    std::cout << "Welche Zahl soll gesucht werden?: ";
    std::cin >> search;
    std::vector<int> array = {1, 4, 8, 11, 33, 58, 274, 2222};
    std::cout << "Suchen " << search << " im Array...\n";
    if (binarySearch(array, search, 0, array.size()))
        std::cout << "Die Zahl ist im Array vorhanden!\n";
    else
        std::cout << "Die Zahl ist nicht da :((\n";
}