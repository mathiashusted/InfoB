/*
Code von gromdimon
12.05.2023
*/

//**********************************************************************************************
// AUFGABE 2

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// In dieser Aufgabe geht es um das Tankstellenproblem. Wir befinden uns am
// Anfang einer seeeeehr langen Straße und möchten mit unserem Auto bis zum Ende
// der Straße fahren. Die Länge der Straße beträgt L km. Entlang dieser Straße
// befinden sich n Tankstellen. Für 1 ≤ i ≤ n bezeichnet li die Entfernung der
// i-ten Tankstelle zum Startpunkt (gemessen in km). Zusammengefasst gilt: 0 ≤
// l1 ≤ l2 ≤ · · · ≤ ln−1 ≤ ln ≤ L. Wir nehmen an, dass beim Startpunkt der Tank
// unseres Autos maximal gefüllt ist (natürlich mit Benzin und nicht mit
// Diesel). Mit einer Tankfüllung können wir aber nicht mehr als M km fahren.
// Die Straße kann jedoch so lang sein, dass wir es nicht mit einer Tankfüllung
// bis zum Ende der Straße schaffen, sondern unter Umständen mehrere Male
// unterwegs tanken müssen. Als umweltbewusste Bürgerinnen und Bürger sind wir
// natürlich daran interessiert, so wenig wie möglich Tankstellen anzufahren, an
// denen wir tanken müssen. 
// a) Formuliert das Tankstellenproblem als algorithmisches Problem. 
// b) Entwickelt einen gierigen Algorithmus zur Lösung des Tankstellenproblems. 
// Gebt den Algorithmus verbal oder in Pseudocode an. Nennt die Greedy-Strategie, 
// die dem Algorithmus zugrunde liegt. 
// c) Wendet euren Algorithmus auf die folgende Eingabe an: l1 = 4, l2 = 5, l3 = 13, 
// l4 = 19, l5 = 28, l6 = 30, l7 = 34, l8 = 36, l8 = 39, L = 42, M = 13. 
// d) Die 4. Tankstelle aus c) muss wegen Bauarbeiten geschlossen werden. Wie verhält 
// sich Ihr Algorithmus nun? 
// e) Begründet mithilfe des Austauscharguments, warum euer Algorithmus eine optimale 
// Lösung findet. 
// f) (Zusatzaufgabe) Implementiert den Algorithmus in C++

// a) Das Tankstellenproblem ist ein Optimierungsproblem, bei dem wir die Anzahl
// der Tankstellen minimieren wollen, die wir anfahren müssen, um mit unserem
// Auto eine Strecke L zurückzulegen. Die Eingabe besteht aus der Länge L der
// Straße, der maximalen Reichweite M unseres Autos und den Entfernungen li der
// Tankstellen zum Startpunkt. Die Ausgabe ist die minimale Anzahl an
// Tankstellen, die wir anfahren müssen, um mit unserem Auto die Strecke L
// zurückzulegen.

// b) Wir fahren so weit wie möglich, bis wir tanken müssen. Dann fahren wir zur
// letzten Tankstelle zurück, an der wir getankt haben, und tanken voll. Dann
// fahren wir wieder so weit wie möglich, bis wir tanken müssen. Diesen Vorgang
// wiederholen wir, bis wir am Ende der Straße angekommen sind. Die
// Greedy-Strategie, die diesem Algorithmus zugrunde liegt, ist die, dass wir
// immer so weit wie möglich fahren, bevor wir tanken müssen.

// c) Wir fahren so weit wie möglich, bis wir tanken müssen. Dann fahren wir zur
// letzten Tankstelle zurück, an der wir getankt haben, und tanken voll. Dann
// fahren wir wieder so weit wie möglich, bis wir tanken müssen. Diesen Vorgang
// wiederholen wir, bis wir am Ende der Straße angekommen sind. Die
// Greedy-Strategie, die diesem Algorithmus zugrunde liegt, ist die, dass wir
// immer so weit wie möglich fahren, bevor wir tanken müssen.

// d) Wir fahren so weit wie möglich, bis wir tanken müssen. Dann fahren wir zur
// letzten Tankstelle zurück, an der wir getankt haben, und tanken voll. Dann
// fahren wir wieder so weit wie möglich, bis wir tanken müssen. Diesen Vorgang
// wiederholen wir, bis wir am Ende der Straße angekommen sind. Die
// Greedy-Strategie, die diesem Algorithmus zugrunde liegt, ist die, dass wir
// immer so weit wie möglich fahren, bevor wir tanken müssen.

// e) Wir fahren so weit wie möglich, bis wir tanken müssen. Dann fahren wir zur
// letzten Tankstelle zurück, an der wir getankt haben, und tanken voll. Dann
// fahren wir wieder so weit wie möglich, bis wir tanken müssen. Diesen Vorgang
// wiederholen wir, bis wir am Ende der Straße angekommen sind. Die
// Greedy-Strategie, die diesem Algorithmus zugrunde liegt, ist die, dass wir
// immer so weit wie möglich fahren, bevor wir tanken müssen.

// f) Wir fahren so weit wie möglich, bis wir tanken müssen. Dann fahren wir zur
// letzten Tankstelle zurück, an der wir getankt haben, und tanken voll. Dann
// fahren wir wieder so weit wie möglich, bis wir tanken müssen. Diesen Vorgang
// wiederholen wir, bis wir am Ende der Straße angekommen sind. Die
// Greedy-Strategie, die diesem Algorithmus zugrunde liegt, ist die, dass wir
// immer so weit wie möglich fahren, bevor wir tanken müssen.

int calculate_min_stops(int L, int M, vector<int> li) {
  li.push_back(L); // Fuege das Ende der Straße als Tankstelle hinzu
  int i = 0;
  int count = 0;
  int pos = 0;
  while (i < static_cast<int>(li.size())) {
    if (li[i] == L) { // Falls wir am Ende der Straße angekommen sind, breche ab
      if (L - pos > M) { // Falls wir mit der aktuellen Tankfuellung nicht
                         // bis zum Ende der Straße kommen, fahre zur
                         // letzten Tankstelle zurueck und tanke voll
        pos = li[i - 1];
        count++;
        if (L - pos > M) { // Falls wir mit der aktuellen Tankfuellung nicht
                           // bis zum Ende der Straße kommen, breche ab
          return -1;
        }
      }
    }
    if (li[i] - pos > M) { // Pruefe, ob wir mit der aktuellen Tankfuellung bis
                           // zur naechsten Tankstelle kommen
      pos = li[i - 1]; // Falls nicht, fahre zur letzten Tankstelle zurueck und
                       // tanke voll
      if (li[i] - pos > M) { // Falls wir mit der aktuellen Tankfuellung nicht
                           // bis zum Ende der Straße kommen, breche ab
          return -1;
        }
      count++;
    }
    i++;
  }
  return count;
}

int main() {
  int L = 42; // Länge der Straße
  int M = 13; // maximale Reichweite des Autos
  vector<int> li = {
      4,  5,  13, 28,
      30, 34, 36, 39}; // Entfernungen der Tankstellen zum Startpunkt
//   cout << "L = " << L << endl;
//   cin >> L;
//   cout << "M = " << M << endl;
//   cin >> M;
//   cout << "(Achting! Gibt's nur 9 Tankstellen!!) li = ";
//   for (int i = 0; i < static_cast<int>(li.size()); i++) {
//     cout << li[i] << " ";
//   }

  int count = calculate_min_stops(L, M, li);
  if (count == -1) {
    cout << "Es ist nicht möglich, mit dem Auto die Strecke L zurückzulegen."
         << endl;
    return 0;
  }
  cout << "Die minimale Anzahl an Tankstellen, die wir anfahren müssen, um mit "
          "unserem Auto die Strecke L zurückzulegen, ist: "
       << count << endl;
  return 0;
}
