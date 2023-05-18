/*
Gruppe M. Husted, A. Malze, S. Kutscher

Bestimme die Anzahl der Runden, die benötigt werden.

Zuerst wird die While-Schleife aufgerufen. Diese wird sqrt(n) Mal abgerufen, da die Liste bei jedem Durchlauf halbiert wird.
Das liegt daran, dass alle Elemente mit ihrem Nachbarelement verglichen werden, und eines davon wird gelöscht.

Innerhalb der While-Schleife wird wiederum eine For-Schleife eröffnet, die wieder alle n Elemente innerhalb dieser Liste überprüft.
Folglich muss dies auch n Mal passieren.


Innerhalb der For-Schleife wird das nicht benötigte Element entfernt. Das wird wieder über eine For-Schleife (removeElem) geregelt, die
alle Elemente nacheinander nach hinten schiebt. Im schlechtesten Fall passiert das auch n Mal. (wenn alle Variablen ganz bis
nach hinten verschoben werden müssen)

Die Anzahl der Runden, die benötigt werden beträgt also im schlechtesten Fall
n = vec.size()
T(0) = 0 (While beginnt nicht)
T(n) = sqrt(n) * n * n



Unten ist eine Funktion, die die Anzahl der Runden für ein beliebiges Array liefert.
*/

#include <iostream>
#include <vector>

// Vor: Keine
// Erg: Keins
// Eff: Entfernt i-tes Element aus dem Vektor
void removeElem(std::vector<int> & input, size_t index, int & count) {
    if (index >= input.size()-1) {
        input.pop_back();
        return;
    }
    for (size_t i = index; i < input.size()-1; i++) {
        count++;
        input[i] = input[i+1];
    }
    input.pop_back();
}


// Vor: Keiner
// Erg: Gibt minimales Element zurück.
// Eff: Zeigt am Ende die Laufzeit an.
int turnierMin(std::vector<int> & input) {
    if (input.empty()) return 0;
    int count = 0;
    std::vector<int> candidates = input;
    while (candidates.size() > 1) {
        std::cout << "Current size: " << candidates.size() << std::endl;
        count++;
        for (size_t i = 0; i < (candidates.size() - 1); i++) {
            count++;
            if (candidates[i] < candidates[i+1]) {
                std::cout << "Removing " << candidates[i+1] << std::endl;
                removeElem(candidates, (i+1), count);
                
            } else {
                std::cout << "Removing " << candidates[i] << std::endl;
                removeElem(candidates, i, count);
            }
        }
    }
    std::cout << "Laufzeit: " << count << std::endl;
    return candidates[0];
}

int main() {
    std::vector<int> array = {6,23,98,55,22, (-128), 28, 46762, (-2785), (-58274), 28, 7276, 7, 2, 2, 3};
    std::cout << "Anzahl der Elemente im Array: " << array.size() << std::endl;
    std::cout << turnierMin(array) << std::endl;
}