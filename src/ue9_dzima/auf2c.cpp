/*
gromdimon
16.06.2023
*/

//**********************************************************************************************
// Aufgabe 2c

// Implementierung von Queue mit Hilfe von verketteten Listen

#include "queue.hpp"
#include <iostream>
#include <string>
using namespace std;

template <typename E> class queue_list : public queue<E> {
private:
  struct node {
    E data;
    node *next;
  };
  node *head;
  node *tail;

public:
  queue_list() : head(nullptr), tail(nullptr) {}
  queue_list(const queue_list<E> &other) : queue_list() {
    node *current = other.head;
    while (current) {
      enqueue(current->data);
      current = current->next;
    }
  }
  ~queue_list() {
    while (!is_empty()) {
      dequeue();
    }
  }
  bool is_empty() const { return head == nullptr; }
  E dequeue() {
    if (is_empty()) {
      throw "Queue is empty";
    }
    node *tmp = head;
    E data = tmp->data;
    head = head->next;
    delete tmp;
    return data;
  }
  E front() const {
    if (is_empty()) {
      throw "Queue is empty";
    }
    return head->data;
  }
  void enqueue(E x) {
    node *tmp = new node;
    tmp->data = x;
    tmp->next = nullptr;
    if (is_empty()) {
      head = tmp;
      tail = tmp;
    } else {
      tail->next = tmp;
      tail = tmp;
    }
  }
};

int main() {
  queue_list<string> q;
  q.enqueue("Hallo");
  q.enqueue("Welt");
  q.enqueue("!");
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  return 0;
}