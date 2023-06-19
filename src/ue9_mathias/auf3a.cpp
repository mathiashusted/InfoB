// Gruppe M. Husted, A. Malze, S. Kutscher

#include <iostream>
#include "queue.hpp"
#include <utility>

template <typename K, typename V> class adtdict {
    private:
        struct Node {
            K key;
            V value;
        };
        
        Node* dictionary;

        unsigned capacity;
        unsigned size;

        void moveBack(K starting) {
            if (size == capacity)
                return;
            for (unsigned i = this->size; i > starting; i--) {
                this->dictionary[i].key = this->dictionary[i-1].key;
                this->dictionary[i].value = this->dictionary[i-1].value;
            }
            this->dictionary[starting].key = K();
            this->dictionary[starting].value = V();
            this->size++;
        }

    public:
        adtdict(unsigned argCapacity) {
            this->dictionary = new Node[argCapacity];
            this->capacity = argCapacity;
            this->size = 0;
        }

        ~adtdict() {
            delete this->dictionary;
        }


        void printAll() {
            for (unsigned i = 0; i < this->size; i++) {
                std::cout << "Index " << i <<": Key: " << this->dictionary[i].key << ", value: " << this->dictionary[i].value << "\n";
            }
        }

        void put(K argKey, V argValue) {
            if (this->size == 0 && this->size < this->capacity) {
                this->size++;
                this->dictionary[0].key = argKey;
                this->dictionary[0].value = argValue;
            }
            else {
                for (unsigned i = 0; i < this->size; i++) {
                    if (this->dictionary[i].key == argKey) {
                        this->dictionary[i].value = argValue;
                        return;
                    }
                    else if (this->dictionary[i].key > argKey) {
                        if (this->size != this->capacity) {
                            moveBack(i);
                            this->dictionary[i].key = argKey;
                            this->dictionary[i].value = argValue;
                        }
                        return;
                    }
                    else if (this->dictionary[i].key < argKey && i == (this->size - 1)) {
                        if (this->size != this->capacity) {
                            this->dictionary[i+1].key = argKey;
                            this->dictionary[i+1].value = argValue;
                            this->size++;
                        }
                        return;
                    }
                }
            }
        }

        V get(K argKey) {
            // Binärsuche
            unsigned l = 0;
            unsigned r = this->size - 1;
            unsigned mid;
            while (l < r) {
                mid = l + ((r - l) / 2);
            }
        }
};


int main() {
    adtdict<int,int> dict(10);
    dict.put(1, 62);
    dict.put(2, 172982);
    dict.put(4, 81);
    dict.put(5, 1);
    dict.put(7, 29);
    dict.put(6, 198);
    dict.put(3, 28);
    dict.put(2, 2);
    dict.printAll();
}