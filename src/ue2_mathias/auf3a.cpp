// Gruppe M. Husted, A. Malze, S. Kutscher
#include <vector>

//3a) Betrachten Sie den folgenden C++-Code und geben Sie für alle Variablen den Gültigkeitsbereich an.

int main(){
    int v1 = 32; // v1 ab hierinnerhalb von main() gültig
    double i = 7.0; // i ab hier innerhalb von main() gültig
    for(int i=2; i< 30; i++){ // i ausschließlich innerhalb der For-Schleife gültig (das "alte" i wird innerhalb der Schleife "vergessen")
        v1 *= i;
    }
    std::vector<std::vector<int>> vec = { { 1, 2, 3 }, // vec innerhalb von main gültig
                            { 4, 5, 6 },
                            { 7, 8, 9, 4 } };
    for (i = 0; i<vec.size(); i++){ // Neues i wird für diese Schleife deklariert (das "alte" i wird wieder innerhalb der Schleife ignoriert)
        int v1=20; // Dieses v1 ist nur innerhalb der for-Schleife gültig. Das äußere v1 "vergessen"
        for (unsigned int j=0; j<vec[i].size();j++){ // j innerhalb der Schleife gültig
            v1 = vec[i][j]; // Bezieht sich auf das "innere" v1
        }
        v1+=1;
    }
}