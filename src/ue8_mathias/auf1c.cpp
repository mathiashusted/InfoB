// Gruppe M. Husted, A. Malze, S. Kutscher

#include <iostream>

/* Wir betrachten eine Klasse, die immer ein Vielfaches von Pi enthält.
Da Pi sich niemals ändert, sollte const benutzt werden.
pf (unsere "Zählervariable") hingegen, ändert sich bei jedem Aufruf von der Methode add()
und kann dementsprechend nicht als Konstante betrachtet werden.
*/

class piMultiplier {
    private:
        const double pi = 3.141;
        double pf = 0; // Zählervariable
    public:
        // Vor:
        // Erg: 
        // Eff: Gibt aus, dass eine Instanz initialisiert wurde.
        piMultiplier() {
            std::cout << "piMultiplier wurde initialisiert.\n";
        }
        // Vor:
        // Erg:
        // Eff: Addiert ein Vielfaches von Pi (factor*pi) zu unserer Zählervariable pf
        void add(double factor) {
            this->pf += this->pi*factor;
        }
        // Vor:
        // Erg: Aktueller Stand der Zählervariable
        // Eff:
        double currentPf() {
            return this->pf;
        }
};

int main() {
    piMultiplier p;
    p.add(1);
    std::cout << "Unser aktuelles Pi ist: " << p.currentPf() << "\nNun addieren wir 3 weitere Pi\n";
    p.add(3);
    std::cout << "Jetzt ist es " << p.currentPf() << "\n";
}