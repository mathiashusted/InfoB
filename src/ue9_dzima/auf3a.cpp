/*
gromdimon
17.06.2023
*/

//**********************************************************************************************
// Aufgabe 3a

// Implementierung von Dictionary mit Hilfe von dynamischen Arrays

#include "auf3a.hpp"
#include <iostream>
#include <string>
using namespace std;

template <typename K, typename V>
class dictionary_array : public dictionary<K, V> {
private:
  struct entry {
    K key;
    V value;
  };
  entry *data;
  int size;
  int capacity;

public:
  dictionary_array() : data(nullptr), size(0), capacity(0) {}
  dictionary_array(const dictionary_array<K, V> &other) : dictionary_array() {
    for (int i = 0; i < other.size; i++) {
      put(other.data[i].key, other.data[i].value);
    }
  }
  ~dictionary_array() { delete[] data; }
  bool is_empty() const { return size == 0; }
  V put(K key, V value) {
    for (int i = 0; i < size; i++) {
      if (data[i].key == key) {
        V old_value = data[i].value;
        data[i].value = value;
        return old_value;
      }
    }
    if (size == capacity) {
      capacity = capacity == 0 ? 1 : capacity * 2;
      entry *tmp = new entry[capacity];
      for (int i = 0; i < size; i++) {
        tmp[i] = data[i];
      }
      delete[] data;
      data = tmp;
    }
    data[size].key = key;
    data[size].value = value;
    size++;
    return V();
  }
  V get(K key) const {
    for (int i = 0; i < size; i++) {
      if (data[i].key == key) {
        return data[i].value;
      }
    }
    throw "Key not found";
  }
  void remove(K key) {
    if (is_empty()) {
      throw "Dictionary is empty";
    }
    for (int i = 0; i < size; i++) {
      if (data[i].key == key) {
        for (int j = i; j < size - 1; j++) {
          data[j] = data[j + 1];
        }
        size--;
        return;
      }
    }
  }
};

int main() {
  dictionary_array<string, int> dict;
  dict.put("a", 1);
  dict.put("b", 2);
  dict.put("c", 3);
  dict.put("d", 4);
  dict.put("e", 5);
  cout << "Get a: " << dict.get("a") << endl;
  cout << "Get b: " << dict.get("b") << endl;
  cout << "Get c: " << dict.get("c") << endl;
  cout << "Get d: " << dict.get("d") << endl;
  cout << "Get e: " << dict.get("e") << endl;
  dict.remove("a");
  dict.remove("b");
  dict.remove("c");
  dict.remove("d");
  dict.remove("e");
  cout << "Empty dict proof(0=False, 1=True): " << dict.is_empty() << endl;
}
