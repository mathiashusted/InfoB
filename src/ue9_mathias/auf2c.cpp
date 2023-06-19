// Gruppe M. Husted, A. Malze, S. Kutscher
/*
Hier wurde die Version aus Aufgabe 2a implementiert. Es wurde zusätzlich eine Fetch-Funktion eingebaut,
um das n-te Element der Liste zurückzugeben.
*/

#include <iostream>

template <typename E> class adtqueue {
    private:
        struct Node {
            E data;
            Node* next;
        };
        Node* head;
        Node* tail;
    public:
        // Eff: Objekt wird erstellt, head und tail jeweils NULL.
        adtqueue() {
            this->head = NULL;
            this->tail = NULL;
        }
        // Eff: Alle Elemente werden gelöscht.
        ~adtqueue() {
            Node* temp = this->head;
            while (temp->next != NULL) {
                temp = this->head->next;
                delete this->head;
                this->head = temp;
            }
            delete temp;
        }
        // Erg: True, falls head == NULL, sonst false
        bool is_empty() {
            return (head == NULL) ? true : false;
        }
        // Eff: Das Argument contents wird als neues Element eingefügt
        void enqueue(E contents) {
            Node* n = new Node;
            n->data = contents;
            n->next = NULL; // Das neue Element hat eindeutig noch keinen Nachfolger
            if (this->is_empty()) { // Falls Queue leer, ist das neue Element head und tail gleichzeitig
                this->head = n;
                this->tail = n;
            }
            else {
                this->tail->next = n;
                this->tail = n;
            }
        }
        // Eff: Falls Liste nicht leer, lösche erstes Element.
        void dequeue () {
            if (!this->is_empty()) {
                Node* temp = this->head->next;
                delete this->head;
                this->head = temp;
                delete temp;
            }
        }
        // Erg: n-tes Element der Queue. Falls Liste leer wird immer -1 zurückgegeben.
        E fetch(unsigned n) {
            Node* node = this->head;
            unsigned i = 0;
            while (i < n && node->next != NULL) {
                node = node->next;
                i++;
            } ;
            return (node != NULL) ? node->data : -1;
        }
        // Erg: Erstes Element der Liste.
        E front() {
            return this->head;
        }
};¨

int main() {
    adtqueue<int> adt;
    adt.enqueue(27);
    adt.enqueue(22);
    adt.enqueue(682);
    adt.enqueue(916);
    adt.enqueue(7168);
    adt.enqueue(466); // Queue ist nun: [27, 2, 682, 916, 7168, 466]
    adt.dequeue();
    adt.dequeue();    // Queue ist nun: [682, 916, 7168, 466]
    for (unsigned i = 0; i < 4; i++) {
        std::cout << "Das " << i << "-te Element ist: " << adt.fetch(i) << "\n";
    }
}