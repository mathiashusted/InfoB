/* Gruppe M. Husted, A. Malze, S. Kutscher

Quelle: https://cplusplus.com/doc/tutorial/files/

In C++ gibt es die Möglichkeit, mit Hilfe von fstream Dateien zu öffnen und zu manipulieren.

Der Syntax sieht wie folgt aus:
*/

#include <iostream>
#include <fstream>

int main() {
    std::ofstream file; // Wir legen eine Variable für die Datei fest. (ofstream = schreiben; Können auch mit ifstream sowohl lesen als auch schreiben)
    file.open("datei.txt"); // Wir öffnen die Datei
    file << "Hello world\n"; // Wir schreiben in die Datei (ähnlich zu cout)
    file.close(); // Wir schließen die Datei wieder
}

