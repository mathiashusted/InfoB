// Gruppe M. Husted, A. Malze, S. Kutscher
// 3c) Finden Sie je einen Anwendungsfall, in dem eine for, while und die weitere Schleife gegenüber
// den anderen Schleifenarten zu bevorzugen ist.

#include <iostream>

int main() {
    for (int i = 0; i < 10; i++) {
        
    }
// Die For-Schleife ist bei einer normalen Schleife mit fester Zählervariable zu bevorzugen, da die Zählervariable
// nur innerhalb der Schleife gebraucht wird, und danach wieder "verschwindet" (damit nicht im Speicher bleibt)
    int sum;
    while (sum < 20) {
        sum += 1;
    }
// Die While-Schleife ist zu bevorzugen, falls eine Variable außerhalb der Schleife die Bedingung der Schleife stellen soll,
// und diese Variable nach dem Schleifenende beibehalten werden soll.
    do {

    } while (true);
// Wenn die Bedingung (außerhalb der Schleife) nicht fest ist, der Code dennoch auf alle Fälle mindestens ein Mal ausgeführt werden soll,
// kann man eine Do-While-Schleife einsetzen.
}