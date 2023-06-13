// Gruppe M. Husted, A. Malze, S. Kutscher

#include <iostream>
#include <string>

class Escooter {
    private:
        unsigned ps;
        unsigned gewicht;
        std::string farbe;
        unsigned km;
    public:
        //Vor:
        //Erg: 
        //Eff: Erstellt neue Instanz von Escooter
        Escooter(unsigned aps, unsigned agewicht, std::string afarbe, unsigned akm) {
            this -> ps = aps;
            this -> gewicht = agewicht;
            this -> farbe = afarbe;
            this -> km = akm;
        }
        //Vor:
        //Erg:
        //Eff: Löscht Instanz von Escooter
        ~Escooter() {
            std::cout << "Der E-Scooter wurde gelöscht.\n";
        }
        // Überlädt den < Operator, sodass immer die PS-Zahl verglichen wird
        bool operator<(const Escooter & s) {
            return (this -> ps < s.ps);
        }
        // Vor:
        // Erg:
        // Eff: Ändert die PS-Zahl
        void motorAufruesten(unsigned newPs) {
            this -> ps = newPs;
        }
        // Vor:
        // Erg:
        // Eff: Ändert die Farbe
        void umlackieren(std::string newFarbe) {
            this -> farbe = newFarbe;
        }
        // Vor:
        // Erg:
        // Eff: Erhöht die km-Zahl
        void fahren(unsigned gefahreneKm) {
            this -> km += gefahreneKm;
        }
        // Vor:
        // Erg:
        // Eff: Ändert das Gewicht
        void beladen(unsigned newGewicht) {
            this -> gewicht = newGewicht;
        }

        // Vor:
        // Erg: Gibt die Farbe des E-Scooters zurück
        // Eff: 
        std::string getFarbe() {
            return this -> farbe;
        }
};

int main() {
    Escooter vespa(5, 80, "rot", 0);
    vespa.motorAufruesten(7);
    vespa.fahren(285);

    Escooter peugeot(4, 76, "grün", 0);
    peugeot.umlackieren("gelb");

    if (vespa < peugeot)
        std::cout << "Die Vespa hat weniger PS\n";
    else
        std::cout << "Die Vespa hat mehr PS\n";
    
    std::cout << "Der Peugeot hat die Farbe " << peugeot.getFarbe() << std::endl;
}