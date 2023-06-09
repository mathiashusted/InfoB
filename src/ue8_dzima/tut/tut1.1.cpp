/*
Code von gromdimon
09.06.2023
*/

//**********************************************************************************************
// AUFGABE 1

#include <iostream>
using namespace std;


const int MAX_SIZE = 100;

class Heap {
public:
    Heap() : size(0) {}   // Konstruktor

    void insert(int x) {
        if (size == MAX_SIZE) {
            cout << "Heap is full" << endl;
            return;
        }
        arr[size] = x;
        int i = size;
        while (i > 0 && arr[i] > arr[(i-1)/2]) {
            swap(arr[i], arr[(i-1)/2]);
            i = (i-1)/2;
        }
        size++;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    int arr[MAX_SIZE];
    int size;
};

int main() {
    Heap h;
    h.insert(3);
    h.insert(2);
    h.insert(1);
    h.insert(5);
    h.insert(4);
    h.print();
    return 0;
}