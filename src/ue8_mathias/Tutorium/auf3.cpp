#include <iostream>
#include <vector>

class Konto {
    private:
        unsigned pin;
        int kontostand;
    public:
        Konto(unsigned argPin) {
            this -> pin = argPin;
            this -> kontostand = 0;
        }
        ~Konto() {
            std::cout << "Ich wurde gelöscht\n";
        }
        void abheben(unsigned pin, unsigned betrag) {
            if (pin == this->pin)
                this->kontostand -= betrag;
            else
                std::cout << "PIN falsch\n";
        }
        void einzahlen(unsigned pin, unsigned betrag) {
            if (pin == this->pin)
                this->kontostand += betrag;
            else
                std::cout << "PIN falsch\n";
        }
        void mehr_einzahlen(unsigned pin, std::vector<unsigned> betraege) {
            if (pin == this->pin) {
                for (size_t i = 0; i < betraege.size(); i++) {
                    this->kontostand += betraege[i];
                }
            }
            else
                std::cout << "PIN falsch\n";
        }
};

int main() {

}