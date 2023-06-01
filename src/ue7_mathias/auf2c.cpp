// Gruppe M. Husted, A. Malze, S. Kutscher
/*
Die Increase Funktion versucht vermutlich, die Variable, auf die sie zeigt, zu inkrementieren.

Allerdings funktioniert der Code in der Form nicht. Was passiert ist, dass die increase-Funktion
versucht, die Adresse selbst zu inkrementieren, was zu undefiniertem Verhalten führt. Die Variable
wird also nicht inkrementiert.

In C++ hat der ++ Operator eine höhere "Priorität" als *. Deswegen wird zuerst die Pointer-Variable
inkrementiert, und daraufhin wird auf den Wert dieser Variable zugegriffen.
Eine "korrigierte" Version wurde in increaseImproved implementiert.
*/

#include <iostream>


// Führt zu undefiniertem Verhalten
void increase(int* aptr){
    *(aptr)++;
}

// Vor: Referenz wird als Argument weitergegeben
// Erg: Keins
// Eff: 
void increaseImproved(int* aptr){
    (*aptr)++;
}

int main() {
    int a = 3;
    std::cout << "a beträgt " << a << "\n";
    increase(&a);
    std::cout << "Increase Funktion wurde angewendet, a beträgt immer noch " << a << "\n";
    increaseImproved(&a);
    std::cout << "increaseImproved wurde angewendet, a beträgt nun " << a << "\n";
}