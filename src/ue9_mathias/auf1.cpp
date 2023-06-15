// Gruppe M. Husted, A. Malze, S. Kutscher

/*
Aufgabe 1a:

Struktur:
|Tier
unsigned gewicht, unsigned groesse, std::string gattung
-fortbewegen()
-atmen()
-essen()
    | Säugetier
        | Hund
        -anbellen(Tier t)
        -fortpflanzen(Hund t)
            | Pudel
    | Insekt
        | Biene

*/

// Aufgabe 1b:

#include <iostream>
#include <string>

class Tier {
    private:
        unsigned gewicht;
        unsigned groesse;
        std::string gattung;
    public:
        Tier(unsigned newGewicht, unsigned newGroesse, std::string newGattung) {
            this -> gewicht = newGewicht;
            this -> groesse = newGroesse;
            this -> gattung = newGattung;
            std::cout << "Neues Tier erstellt\n";
        }
        virtual void fortbewegen() {
            std::cout << "Ich bewege mich fort.\n";
        }
        virtual void atmen() {
            std::cout << "Ich atme\n";
        }
        virtual void essen() {
            std::cout << "Ich esse\n";
        }
};

class Saeugetier : public Tier {

};

class Hund : public Saeugetier {
    public:
        virtual void anbellen(Tier t) {
            std::cout << "Wuf!\n";
        }
        void fortpflanzen(Hund h) {
            std::cout << "Neuer Wuf!\n";
        }
};

class Pudel : public Hund {
    public:
        void anbellen(Tier t) {
            std::cout << "Waf!\n";
        }
};


int main() {

}

/*
Aufgabe 1c:

Die Methoden von der Klasse Tier (fortbewegen(), atmen(), essen()) wurden virtualisiert, da es für
Tiere viele unterschiedliche Arten gibt, das zu erreichen. Fortbewegung kann bspw. durch Schwimmen
oder Fliegen erreicht werden, Atmen durch Lungen oder Kiemen, Nahrung kann ebenfalls über viele
Wege aufgenommen werden. Daher kann man as schwer verallgemeinern.

Die Methode fortpflanzen(Hund h) wurde bei der Klasse Hund implementiert, da es doch recht selten
vorkommt, dass sich eine andere Tierart mit einem Hund fortpflanzt. Die Funktion wurde aber nicht
virtualisiert, da es bei Hunden ein allgemeingültiger Vorgang ist. Die Funktion anbellen(Tier t)
wurde nach langer Überlegung virtualisiert, da nach gründlicher Analyse vieler Youtube-Clips
und Befragung befreundeter Hundebesitzer festgestellt wurde, dass nicht jeder Hund gleich bellt.
Tatsächlich hat unsere Umfrage ergeben, dass es sich bei einem Pudel vielmehr um ein sogenanntes
"Waf" als das traditionelle "Wuf" handelt. Dies haben wir dementsprechend sofort in unserer Klasse
korrigiert, um ein möglichst realitätsnahes Anbellen in unserer C++-Implementation zu erreichen.
*/