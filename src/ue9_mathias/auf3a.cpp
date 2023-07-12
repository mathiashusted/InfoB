// Gruppe M. Husted, A. Malze, S. Kutscher

#include <iostream>
#include "queue.hpp"

template <typename K, typename V> class adtdict {
    private:
        struct Node {
            K key;
            V value;
        };
        
        Node* dictionary;

        unsigned capacity;
        unsigned size;

        // Hilfsfunktion
        // Eff: Verschiebt alle Elemente ab starting nach hinten.
        void moveBack(K starting) {
            if (this->size == this->capacity)
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
        // Eff: Erstellt neue Instanz von actdict, mit Kapazität von argCapacity und Size 0
        adtdict(unsigned argCapacity) {
            this->dictionary = new Node[argCapacity];
            this->capacity = argCapacity;
            this->size = 0;
        }

        // Eff: Löscht die Instanz von Node
        ~adtdict() {
            delete [] this->dictionary;
        }

        // Hilfsfunktion
        // Eff: Printet alle Elemente im Wörterbuch (Überblick)
        void printAll() {
            for (unsigned i = 0; i < this->size; i++) {
                std::cout << "Index " << i <<": Key: " << this->dictionary[i].key << ", value: " << this->dictionary[i].value << "\n";
            }
        }

        // Eff: Falls argKey vorhanden, ersetze seinen Value mit argValue,
        //      sonst: falls Platz im Wörterbuch, suche passende Stellt (sortiert), verschiebe Rest nach hinten
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

        // Erg: Die Stelle im Array, die den Key argKey hat, sonst -1
        // Eff: Suche über Binärsuche nach dem Element mit Key argKey und gebe die Stelle im Array zurück
        int get(K argKey) {
            int l = 0;
            int r = this->size - 1;
            int mid;
            while (l <= r) {
                mid = l + ((r - l) / 2);
                if (this->dictionary[mid].key == argKey)
                    return mid;
                else if (this->dictionary[mid].key < argKey)
                    l = mid+1;
                else
                    r = mid-1;
            }
            return -1;
        }

        // Eff: Lösche, falls vorhanden, die Stelle im Array mit Key argKey,
        //      indem alle Nachfolgerelemente um eine Stelle nach vorne verschoben werden 
        void del(K argKey) {
            int position = this->get(argKey);
            if (position != -1) {
                for (unsigned i = position; i < this->size; i++) {
                    this->dictionary[i].key = this->dictionary[i+1].key;
                    this->dictionary[i].value = this->dictionary[i+1].value;
                }
                this->size--;
            }
            return;
        }

        // Erg: True, falls leer, sonst false
        bool is_empty() {
            return (this->size == 0);
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
    std::cout << "Element mit Key 3 vorhanden? " << ((dict.get(3) != -1) ? "Ja!" : "Nein :(") << "\nLösche Key 6...\n";
    dict.del(6);
    dict.printAll();
    std::cout << "Lösche Key 2...\n";
    dict.del(2);
    dict.printAll();
}