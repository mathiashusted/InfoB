// Gruppe M. Husted, A. Malze, S. Kutscher

#include <iostream>
#include <string>

class Kochfeld {
    private:
        unsigned short stufe;
        unsigned short leistung;
        unsigned short type; // 0 für Gasherd, 1 für Induktion, 2 für Elektro
        bool anzuender;
    public:
        // Vor:
        // Erg:
        // Eff: Erstellt neue Instanz von Kochfeld
        Kochfeld(unsigned short newLeistung, unsigned short newType) {
            this -> stufe = 0;
            this -> leistung = newLeistung;
            this -> type = newType;
        }
        // Vor:
        // Erg: 
        // Eff: Copy Konstruktur von Kochfeld. Erstellt ein neues Kochfeld, basierend auf einem alten.
        Kochfeld(const Kochfeld & argKochfeld) {
            this -> stufe = argKochfeld.stufe;
            this -> leistung = argKochfeld.leistung;
            this -> type = argKochfeld.type;
        }

        // Vor:
        // Erg:
        // Eff: Setzt alle Attribute es Kochfeldes auf die es argKochfeldes
        Kochfeld& operator=(const Kochfeld & argKochfeld) {
            if (this != &argKochfeld) {
                this -> stufe = argKochfeld.stufe;
                this -> leistung = argKochfeld.leistung;
                this -> type = argKochfeld.type;
            }
            return *this;
        }
        // Vor:
        // Erg: True, falls Leistung des Kochfeldes kleiner ist als die des argKochfeldes, sonst false
        // Eff: Überlädt den < Operator
        bool operator<(const Kochfeld & argKochfeld) {
            return (this->leistung < argKochfeld.leistung);
        }
        // Vor:
        // Erg:
        // Eff: Gibt aus, dass das Kochfeld gelöscht wurde. (out of scope)
        ~Kochfeld() {
            std::cout << "Kochfeld wurde gelöscht\n";
        }

        // Vor:
        // Erg:
        // Eff: Falls Gasherd, mache den Anzünder an. Sonst wäre es ziemlich sinnlos...
        void anzuenden() {
            if (this -> type == 0)
                this -> anzuender = true;
            else
                std::cout << "Das wird dir nicht viel bringen :|\n";
        }

        // Vor:
        // Erg:
        // Eff: Schaltet das Kochfeld auf Stufe 1 (bei Gasherd: überprüfe, ob Anzünder an ist)
        void schalteAn() {
            if (this -> type == 0) {
                if (this -> anzuender) {
                    this -> stufe = 1;
                    this -> anzuender = false;
                }
                else std::cout << "Ich brauche Feuer, um anzugehen.\n";
            }
            else this -> stufe = 1;
        }
        // Vor:
        // Erg:
        // Eff: Setze die Stufe auf einen neuen Wert
        void setStufe(unsigned short newStufe) {
            if (this -> stufe >= 1) {
                this -> stufe = newStufe;
                std::cout << "Ich wurde auf Stufe " << this -> stufe << " gesetzt\n";
            }
            else
                std::cout << "Du musst mich erst anschalten.\n";
        }
        // Vor:
        // Erg: Gibt die Leistung des Kochfeldes zurück
        // Eff:
        unsigned short getLeistung() {
            return this -> leistung;
        }

};

int main() {
    Kochfeld gas(1200, 0);
    Kochfeld induktion(2000, 1);
    Kochfeld elektro(2000, 2);

    gas.schalteAn(); // Wird nicht funktionieren, da Gasherde Feuer brauchen.
    induktion.schalteAn(); // Funktioniert :)
    if (gas < induktion)
        std::cout << "Unser Induktionskochfeld ist um " << (induktion.getLeistung() - gas.getLeistung()) << " Watt leistungsstärker als unser Gaskochfeld\n";
    gas.anzuenden();
    gas.schalteAn(); // Funktioniert jetzt mit Feuer
    std::cout << "Gebe ein, welche Stufe das Gaskochfeld haben sollte: ";
    unsigned short gasStufe;
    std::cin >> gasStufe;
    gas.setStufe(gasStufe);
}