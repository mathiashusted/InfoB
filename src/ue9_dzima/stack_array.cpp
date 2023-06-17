/* Informatik B - Sommersemester 2023
Vorlesung am 09.06.2023 + 14.06.2023
Katharina Klost

Implementierung von Stack mit Hilfe von Arrays
*/

#include "stack.hpp"


template <typename E, typename K>
class stack_array: public stack<E>{
private:
   E* array;
   int count; //anzahl an Elementen auf dem Stack
   int capacity; // Kapazität des Array

    /*
    Voraussetzung: keine
    Effekt: Wenn count == capacity gilt, zeigt array auf ein ein neues Array mit den gleichen Elementen an Index 0..count-1 und doppelter Größe
    wenn count < capacity/4 gilt, zeigt array auf ein neues Array mit den gleichen Elementen an Index 0..count-1 und halber Größe.
    Sonst ist nichts geändert.
    */
    void resize(){
        if(count == capacity){
            capacity = capacity*2;
        }
        else if(count < capacity/4){
            capacity = capacity/2;
        }else{
            return;
        }

        // wenn es keinen Defaultkonstruktor für E gibt, gibt es beim Kompilieren einen Fehler
        E* new_array = new E[capacity]; 
        for(int i = 0; i< count; i++){
            new_array[i] = this->array[i];
        }

        delete [] array;
        this->array = new_array;
    }


public:
 stack_array():stack_array(1){
    // ist äquivalent zum Folgenden:
    // this->count = 0;
    // this-> capacity = 1;
    // this->array = E[capacity];
 }

 stack_array(int capacity){
    this->count = 0;
    this->capacity = capacity;
    this->array = new E[capacity];
 }

 stack_array(const stack_array<E> & other):stack_array(other.capacity){
  //die Elemente werden in this->array hineinkopiert
    for(int i=0; i<other.count; i++){
        this->array[i] = other.array[i];
    }
    this-> count = other.count;
 }

 // Copy-Assignment Operator
  stack_array<E> operator=(const stack_list<E>& other){
// wenn other und this nicht das gleiche Objekt sind
    if(this != &other){
      //gibt alten Speicher frei
      delete[] this-> array;

      // passt capacity, count an. Legt ein neues Array an
      this->capacity = other.capacity;
      this->array = new E[this->capacity];
      this ->count = other.count;

      // Kopiere die Elemente aus dem alten Array
      for(int i =0 ; i<other.count;i++){
        this->array[i] = other.array[i];
      }
    }
    return *this;
  }


  // Destruktor ruft pop() auf alle Elemente auf.
  ~stack_array(){
    delete[] array;
  }

 bool is_empty() const{
    return count==0;
  }

  unsigned size() const{
    return this->count;
  }
  E top() const{
    return array[count-1];
 
  }

  E pop(){
    E elem = array[count-1];
    count--;
    resize();
    return elem;
    
  }


  void push(E elem){
    resize();
    array[count] = elem;
    count++;
  }

};