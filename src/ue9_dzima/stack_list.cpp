/* Informatik B - Sommersemester 2023
Vorlesung am 09.06.2023 + 14.06.2023
Katharina Klost

Implementierung von Stack mit Hilfe von verketteten Listen
*/

#include "stack.hpp"


template <typename E>
class stack_list: public stack<E>{
private:
  //ein Knoten hat einen Inhalt und einen Nachfolger
  struct node{
    E value;
    node* next;
  };

  //Verwaltungskopf
  node* head;
  int count;


public:
 stack_list(){
  this->count = 0;
  this-> head = nullptr;
 }

 stack_list(const stack_list<E> & other):stack_list(){
  node* current = other.head;
  //Elemente werden auf einen temporären Stack getan
  stack_list<E> tmp;
  while(current){
    tmp.push(current->value);
    current = current->next;
  }
  //da die Reihenfolge verdreht ist werden sie wieder runter genommen
  while(!tmp.is_empty()){
    this->push(tmp.pop());
  }

 }

 // Copy-Assignment Operator
  stack_list<E> operator=(const stack_list<E>& s){
    // muss nur ausgeführt werden, wenn die Objekte verschieden sind
    if(this != &s){

      // alter Stack wird geleert
      while(!this->is_empty()){
        this->pop();
      }

      // und wie im Copy-Construktor wieder gefüllt
      node* current = s.head;
      stack_list<E> tmp;
      while (current !=nullptr){
        tmp.push(current->value);
        current = current->next;
      }
      while (!tmp.is_empty()){
        this->push(tmp.pop());
      }
    }
    return *this;
  }


  // Destruktor ruft pop() auf alle Elemente auf.
  ~stack_list(){
    while(!this->is_empty()){
      this->pop();
    }
  }

 bool is_empty() const{
    return this->count ==0;
  }

  unsigned size() const{
    return this->count;
  }

  E top() const{
    return this->head->value;
  }

  E pop(){
    // ein Pointer auf den aktuellen head wird gespeichert
    node* oldhead = this-> head;
    // das aktuell oberste Element wird gespeichert
    E elem = oldhead -> value;
    // der neue head ist der Nachfolger vom alten head
    this -> head = this -> head -> next;
    // der Speicher vom alten head wird freigegeben
    delete oldhead;
    // die Anzahl der Elemente wird angepasst
    this-> count --;
    // das zwischengespeicherte Element wird zurückgegeben
    return elem;
  }


  void push(E elem){
    //ein neuer Knoten für das neue Element wird erzeugt
    node* new_node = new node();
    //der Wert des neuen Knoten wird gesetzt
    new_node -> value =elem;
    //der Nachfolge des neuen Knoten ist der alte head
    new_node -> next = this -> head;
    // der neue head ist der neue Knoten
    this -> head = new_node;
    // die Anzahl der Elemente wird angepasst
    this -> count ++;
  }

};