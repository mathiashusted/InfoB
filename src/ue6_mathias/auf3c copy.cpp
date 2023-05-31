// Gruppe M. Husted, A. Malze, S. Kutscher

#include <iostream>
#include <vector>


// Vor: Eingabeliste ist bereits sortiert
// Erg: Die Menge mit Tripeln, bei denen a + b = c
// Eff: Keiner
std::vector<std::vector<int>> triplets(std::vector<int> & inp) {
    std::vector<std::vector<int>> out;
    for (size_t k = 0; k < inp.size(); k++) {
        size_t i = 0;
        size_t j = inp.size()-1;
        while (i < j) {
            if (inp[i] + inp[j] == inp[k]) {
                std::vector<int> help = {static_cast<int>(inp[i]), static_cast<int>(inp[j]), static_cast<int>(inp[k])};
                out.push_back(help);
                i++;
                j--;
            }
            else if (inp[i] + inp[j] < inp[k])
                i++;
            else
                j--;
        }
    }
    return out;
}


int main() {
    std::vector<int> test = {1,2,3,4,5,6,7,8,11,12,23,82};
    std::vector<std::vector<int>> testtriplets = triplets(test);
    std::cout << "Der Eingabevektor besteht aus den folgenden (bereits sortierten) Elementen:\n";
    for (size_t i = 0; i < test.size(); i++) {
        std::cout << test[i] << " ";
    }
    std::cout << "\n\n\n";

    std::cout << "Die Tripel sind wie folgt:\n";
    for (size_t i = 0; i < testtriplets.size(); i++) {
        std::cout << "{" << testtriplets[i][0] << ", " << testtriplets[i][1] << ", " << testtriplets[i][2] << "}\n";
    }
}