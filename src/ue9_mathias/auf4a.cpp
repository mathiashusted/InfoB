/*
Gruppe M. Husted, A. Malze, S. Kutscher

Ein Move-Konstruktor ist analog zum Copy-Konstruktor mit dem entscheidenden Unterschied, dass
das alte Objekt dabei gelöscht wird. Ein Objekt wird sozusagen in ein anderes "verschoben".

Dabei muss daruf geachtet werden, dass man eine sogenannte Rvalue Referenz benutzt, anstatt 
eine normale Referez als Parameter zu übergeben.
Eine Rvalue Referenz sieht folgendermaßen aus:

int && i = 100;

Eine Rvalue Referenz ist eine Referenz, die direkt auf einen Wert im Speicher zeigt, ohne, dafür
ein neues Objekt mit eigener Speicheradresse anzulegen. Das heißt, dass in diesem Fall i selbst
keine Adresse hat, sondern nur als "Alias" für den Wert 100 dient.

Nun, zum Move-Konstruktor:
*/

#include <iostream>

class Animal {
    private:
        int * data;
        //...
    public:
        Animal() {
            //...
        }
        Animal(const Animal && other) {
            std::cout << "Move Konstruktor";
            this->data = other.data;
            delete other.data;
        }
        Animal& operator=(Animal && other) {
            if (this != &other) {
                this -> data = other.data;
                delete other.data;
            }
            return *this;
        }

};

/*
Hierbei werden im Move Konstruktor von der Beispielklasse Animal erst die Daten von other
kopiert, und im Anschluss wird other selbst gelöscht, da seine Daten nun in this sind.
Er kann wie folgt aufgerufen werden
*/
Animal a;
Animal b(std::move(a)); // Move Konstruktor
Animal c = std::move(a); // Move Assignment Operator

/*
Der Move-Assignment-Operator funktioniert analog zum Copy-Assignment-Operator, indem er zuerst
ein neues Objekt erstellt, und dann die Daten aus dem alten löscht.
*/

/*
Source: https://www.educative.io/answers/what-is-a-move-constructor-in-cpp
https://en.cppreference.com/w/cpp/language/move_assignment
*/