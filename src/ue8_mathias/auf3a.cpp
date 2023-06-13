// Gruppe M. Husted, A. Malze, S. Kutscher

#include <iostream>
#include <string>

template <typename K, typename V> class schluesselWertPaar {
    private:
        K key;
        V value;
    public:
        // Vor:
        // Erg:
        // Eff: Erstellt neue Instanz von schluesselWertPaar
        schluesselWertPaar(const K & argKey, const V & argValue) {
            this -> key = argKey;
            this -> value = argValue;
        }
        // Vor:
        // Erg: True, falls Key von this -> key < argPaar.key, sonst false
        // Eff:
        bool operator<(const schluesselWertPaar & argPaar) {
            return (this -> key < argPaar.key);
        }
        // Erg: Key von this
        K getKey() {
            return this -> key;
        }
        // Erg: Value von this
        V getValue() {
            return this -> value;
        }
        // Eff: Key von this wird auf den Key von argKey gesetzt
        void setKey(const K & argKey) {
            this -> key = argKey;
        }
        // Eff: Value von this wird auf Value von argValue gesetzt
        void setValue(const V & argValue) {
            this -> value = argValue;
        }
};

int main() {
    schluesselWertPaar<int, std::string> a(1, "Test");
    schluesselWertPaar<int, std::string> b(18, "Test 2");
    a.setKey(57);
    std::cout << "a < b: " << ((a<b) ? "Ja!" : "Nein!") << "\n";
}