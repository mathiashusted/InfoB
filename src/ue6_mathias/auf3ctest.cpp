// Gruppe M. Husted, A. Malze, S. Kutscher

#include <iostream>
#include <vector>


// Vor: Eingabeliste ist bereits sortiert
// Erg: Die Menge mit Tripeln, bei denen a + b = c
// Eff: Keiner
std::vector<std::vector<int>> triplets(std::vector<int> & inp, int & count) {
    std::vector<std::vector<int>> out;
    for (size_t k = 0; k < inp.size(); k++) {
        size_t i = 0;
        size_t j = inp.size()-1;
        count++;
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
            count++;
        }
    }
    return out;
}


int main() {
    std::vector<int> test;
    int count = 0;
    for (unsigned i = 0; i <= 10000; i++) {
        test.clear();
        for (unsigned j = 0; j < i; j++) {
            test.push_back(j);
        }
        triplets(test, count);
        std::cout << "Die Laufzeit von einem Vektor mit " << i << " Werten beträgt " << count << std::endl;
        count = 0;
    }
    /*std::vector<std::vector<int>> testtriplets = triplets(test, count);
    std::cout << "Der Eingabevektor besteht aus den folgenden (bereits sortierten) Elementen:\n";
    for (size_t i = 0; i < test.size(); i++) {
        std::cout << test[i] << " ";
    }
    std::cout << "\n\n\n";

    std::cout << "Die Tripel sind wie folgt:\n";
    for (size_t i = 0; i < testtriplets.size(); i++) {
        std::cout << "{" << testtriplets[i][0] << ", " << testtriplets[i][1] << ", " << testtriplets[i][2] << "}\n";
    }
    std::cout << "Laufzeit: " << count << " bei einem n^2 von " << (test.size()*test.size()) << std::endl;*/
}