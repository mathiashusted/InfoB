/*
Code von gromdimon
17.05.2023
*/

//**********************************************************************************************
// AUFGABE 1a

#include "hilfsfunktionen.hpp"
#include <iostream>
#include <vector>


void insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < static_cast<int>(arr.size()); i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

std::vector<int> merge(const std::vector<int>& front, const std::vector<int>& back) {
    std::vector<int> merged;
    int i = 0;
    int j = 0;
    
    while (i < static_cast<int>(front.size()) && j < static_cast<int>(back.size())) {
        if (front[i] < back[j]) {
            merged.push_back(front[i]);
            i++;
        } else {
            merged.push_back(back[j]);
            j++;
        }
    }
    
    while (i < static_cast<int>(front.size())) {
        merged.push_back(front[i]);
        i++;
    }
    
    while (j < static_cast<int>(back.size())) {
        merged.push_back(back[j]);
        j++;
    }
    
    return merged;
}


void ultraSort(std::vector<int>& elems) {
    if (static_cast<int>(elems.size()) <= 1) {
        return;
    }
    
    int mid = static_cast<int>(elems.size()) / 3;
    std::vector<int> front(elems.begin(), elems.begin() + mid);
    std::vector<int> back(elems.begin() + mid, elems.end());
    
    insertionSort(front);
    ultraSort(back);
    
    elems = merge(front, back);
}

void ultraSortParam(std::vector<int>& elems, float fraction) {
    if (elems.size() <= 1) {
        return;
    }
    
    int frontLen = fraction * elems.size() / (fraction + 1);
    std::vector<int> front(elems.begin(), elems.begin() + frontLen);
    std::vector<int> back(elems.begin() + frontLen, elems.end());
    
    ultraSortParam(front, fraction);
    ultraSortParam(back, fraction);
    
    elems = merge(front, back);
}

int main() {
    srand(time(NULL));
    double time;
    std::vector<int> array;
    
    for (int size = 10000; size <= 10000000; size *= 10) {
        std::cout << "   " << size << " Elemente:" << std::endl;
        
        // Zufälliges Array testen:
        array = hf::zufalls_array(size);
        
        time = clock();
        ultraSort(array);
        time = clock() - time;
        
        std::cout << "      Zufällig: " << (time / CLOCKS_PER_SEC) << " Sekunden" << std::endl;
        
        // Aufsteigend sortiertes Array testen:
        array = hf::sortiertes_array(size, true);
        
        time = clock();
        ultraSort(array);
        time = clock() - time;
        
        std::cout << "      Aufsteigend: " << (time / CLOCKS_PER_SEC) << " Sekunden" << std::endl;
        
        // Absteigend sortiertes Array testen:
        array = hf::sortiertes_array(size, false);
        
        time = clock();
        ultraSort(array);
        time = clock() - time;
        
        std::cout << "      Absteigend: " << (time / CLOCKS_PER_SEC) << " Sekunden" << std::endl;
        
        // Parametrisierte Ultrasort-Version testen:
        for (float fraction = 0.1; fraction <= 1.0; fraction += 0.1) {
            array = hf::zufalls_array(size);
            
            time = clock();
            ultraSortParam(array, fraction);
            time = clock() - time;
            
            std::cout << "      Parametrisiert (" << fraction << "): " << (time / CLOCKS_PER_SEC) << " Sekunden" << std::endl;
        }
    }
    
    return 0;
}
