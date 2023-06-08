// Gruppe M. Husted, A. Malze, S. Kutscher

#include <iostream>

/* Die folgende Klasse ist unsicher gestaltet. Es kann beliebig auf den Kontostand
außerhalb der Klasse zugegriffen werden, ohne zu überprüfen, ob die Operation überhaupt
erlaubt ist.
*/

class Bankkonto {
    public:
        int kontostand;
        // Vor: Keine
        // Erg: Keins
        // Eff: Setzt den Kontostand auf 0 (neues Konto anlegen)
        Bankkonto() {
            kontostand = 0;
        }
};

/*
Die nachfolgende verbesserte Version hat den Kontostand als private Attribute eingeführt,
d.h. es ist nun eine Variable, auf die nur innerhalb der Klasse zugegriffen werden kann,
man müsste also eine Verifizierung einführen, um zu überprüfen, dass derjenige tatsächlich
Geld eingezahlt hat
*/

class BankkontoImproved {
    private:
        int kontostand;
        void einzahlungVerify(int betrag) {
            // Überprüfe, ob berechtigt.
            kontostand += betrag;
        }
    public:
        // Vor: Keine
        // Erg: Keins
        // Eff: Erstellt ein neues Bankkonto, indem der Kontostand auf 0 gesetzt wird.
        BankkontoImproved() {
            kontostand = 0;
        }
        // Vor: Keine
        // Erg: Gibt den Kontostand aus
        int showKontostand() {
            return kontostand;
        }
        // Vor: Keine
        // Erg: Keins
        // Erg: Ruft die private Hilfsmethode auf, um den Kontostand zu verändern.
        void einzahlen(int betrag) {
            einzahlungVerify(betrag);
        }
};

int main() {
    Bankkonto olaf;
    std::cout << "Olaf hat " << olaf.kontostand << "€ :(\n";
    olaf.kontostand += 1000000000;
    std::cout << "Jetzt hat er aber " << olaf.kontostand << "€ :)\n";
    BankkontoImproved hans;
    std::cout << "Hans hat " << hans.showKontostand() << "€ :( er kann aber nicht so schnell Milliardär werden\n";
    // Es kann nicht auf hans.kontostand zugegriffen werden, sondern es muss über die Hilfsmethode ablaufen
    hans.einzahlen(200);
    std::cout << "Jetzt hat er wenigstens " << hans.showKontostand() << "€.\n";
}