// Gruppe M. Husted, A. Malze, S. Kutscher
/*
In C++ kann das Verhalten von Referenzen mit Hilfe von Pointer "simuliert werden"

Dies funktioniert, indem wir einen Pointer anlegen, der einer Speicheradresse zugewiesen ist.
Daraufhin können wir die auf die Variable zugreifen, der der Pointer zugewiesen wurde, indem wir
für den Pointer i nämlich *i aufrufen. i selbst enthält zwar nur die Adresse, allerdings ist
*i die Variable der Adresse. Das Verhalten ist ähnlich zu einer Rerefenz, bei der wir die Adresse
der Variable einer Funktion weitergeben, und daraufhin mit dem "Alias" die ursprüngliche Variable
manipulieren.
*/

#include <iostream>

// Wir können eine Funktion für diesen Zweck anlegen, indem wir einen Pointer als Parameter nehmen,
// und beim Aufruf der Funktion die Adresse der Variable durchgeben.
// Vor: Referenz der Variable wird als Parameter durchgegeben
// Erg: Keins
// Eff: Die Variable an der Adresse a wird quadriert.
void simulateReference(int* a) {
    (*a) = (*a) * (*a);
}

int main() {
    int a = 1;
    int b = 4;
    int* i = &a; // Der Pointer i wird der Adresse von a zugewiesen
    (*i)++;      // Die Variable, auf die i zeigt (a), wird inkrementiert.
    std::cout << "Address of i (pointer variable): " << i << ", a: " << a << ", Address that i points to: " << &i << ", Value that i points to (a): " << *i << "\n";
    simulateReference(&b); // Funktion wird auf die Adresse von b ausgeführt, damit wird b direkt geändert.
    std::cout << "Result of simulateReference: " << b << "\n"; // b wurde quadriert.
}