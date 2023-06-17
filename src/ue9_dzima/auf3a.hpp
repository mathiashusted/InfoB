/* Informatik B SoSe23
* Spezifikation fuer Aufgabe 3a
*/

#pragma once

template <typename K, typename V>
class dictionary {
public:
    virtual ~dictionary() {}
    virtual bool is_empty() const = 0;
    virtual V put(K key, V value) = 0;
    virtual V get(K key) const = 0;
    virtual void remove(K key) = 0;
};