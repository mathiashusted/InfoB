#include <iostream>
#include <vector>


// Bubblesort aus Aufgabe 3:
// Vor: Keine
// Erg: Sortierter Vektor nach bubbleSort
// Eff: Sortiert den eingegebenen Vektor nach bubbleSort,
// je nachdem ob der Bool aufAb true (aufsteigend) oder false (absteigend)
// Nimmt als Argumente den Vektor input und den Bool aufAb
std::vector<int> bubbleSort(std::vector<int> input, bool aufAb) {
    size_t inc = (input.size()-1); // Unsere verschiebbare "Grenze"
    std::vector<int> output = input; // Die Variable, über die wir input modizifieren
    bool finished = false; // Wenn alles sortiert ist, können wir die Schleife abbrechen
    int buffer[2]; // Puffervariable, um die linke und rechte Vergleichsvariablen zwischenzuspeichern
    while (finished == false) { // Wir sortieren, bis die Liste sortiert ist.
        finished = true; // Liste ist sortiert, bis das Gegenteil "bewiesen" wird
        for (size_t i = 0; i < (inc); i++) {
            buffer[0] = output[i]; 
            buffer[1] = output[(i+1)];
            if (buffer[0] > buffer[1]) { // Links ist größer als rechts => umsortieren
                output[(i+1)] = buffer[0];
                output[i] = buffer[1];
                finished = false; // Liste war offensichtlich noch nicht sortiert
            }
        }
        inc--; // Größter Wert hinten angekommen, Grenze verschieben
    }
    if (aufAb == false) { // Wenn wir die Liste absteigend sortieren wollen, kehren wir den Vektor um
        std::vector<int> outputBuffer = output;
        for (size_t i = 0; i < output.size(); i++) {
            output[i] = outputBuffer[((output.size())-i-1)];
        }
    }
    return output;
}


int main() {
    std::vector<int> test = {30,10,25,100,5,16}; // Sei test die Datei als Vektor dargestellt mit {d1, d2, ..., dn}
    std::vector<int> testOptimized = bubbleSort(test, true); // Ist test aufsteigend sortiert, ist er optimiert
    std::cout << "Datei | Größe" << std::endl;
    for (size_t i = 0; i < testOptimized.size(); i++) {
        std::cout << "d" << (i+1) << " | " << testOptimized[i] << std::endl;
    }
}