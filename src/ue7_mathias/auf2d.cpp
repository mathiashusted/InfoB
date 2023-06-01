// Gruppe M. Husted, A. Malze, S. Kutscher

#include <iostream>

// Vor: Keine
// Erg: Die Summe der in dem Array eingegebenen Zahlen
// Eff: Fragt nach und nach die Zahlen ab, und gibt anschließend die Summe aus.
int sumArray() {
    unsigned k;
    int sum = 0;
    std::cout << "Gebe die Anzahl der Zahlen ein: ";
    std::cin >> k;
    int* arr = new int(k);
    for (int i = 0; i < k; i++) {
        std::cout << "Gebe die " << i << "-te Stelle des Arrays ein: ";
        std::cin >> arr[i];
    }
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int i = sumArray();
    std::cout << "\nDie Summe beträgt: " << i << "\n";
}