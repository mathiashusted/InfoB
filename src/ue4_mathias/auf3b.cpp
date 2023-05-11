#include <iostream>
#include <vector>


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
    std::vector<int> test = {1,2,3,5,4,1,5,7,1,6,0,6,9,7,8,44};
    std::vector<int> testSorted = bubbleSort(test,false);
    for (size_t i = 0; i < testSorted.size(); i++) {
        std::cout << "Das " << i << "-te Element lautet: " << testSorted[i] << std::endl;
    }
}