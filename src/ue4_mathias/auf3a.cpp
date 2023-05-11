// Gruppe M. Husted, A. Malze, S. Kutscher
/*
Bubblesort iteriert durch eine Liste und nimmt dabei immer zwei nebeneinanderstehende Elemente.
{1, 6, 2, 5, 9, 1} -> verglichen werden erst 1, 6 -> 6, 2 -> 2, 5 -> 5, 9 -> 9, 1
Ist das linke Element größer als das rechte, so werden diese getauscht.
Das Ergebnis davon ist, dass im ersten Durchlauf das größte Element garantiert nach hinten verschoben wird.
Die Restliste kann, aber muss nicht danach sortiert sein.
Deswegen können wir nach jedem Durchlauf eine "Grenze" setzen, und im darauffolgenden Durchlauf um eins weniger
iterieren.
Daraus folgt außerdem, dass falls im gesamten Durchlauf KEINE Zahlen getauscht werden, so ist die Liste bereits sortiert.
In dem Fall müssen wir nichts mehr ändern.
Bsp: {1, 6, 2, 5, 9, 1}
1. 1, 6 -> Richtig sortiert
2. 6, 2 -> Tausche => {1, 2, 6, 5, 9, 1}
3. 6, 5 -> Tausche => {1, 2, 5, 6, 9, 1}
4. 6, 9 -> Richtig sortiert
5. 9, 1 -> Tausche => {1, 2, 5, 6, 1, 9}
Nun kann die Grenze bei 9 gesetzt werden: {1, 2, 5, 6, 1 | 9} (im nächsten Durchlauf gibt es 5-1 Iterationen)
1. 1, 2 -> Richtig sortiert
2. 2, 5 -> Richtig sortiert
3. 5, 6 -> Richtig sortiert
4. 6, 1 -> Tausche => {1, 2, 5, 1, 6, 9}
Grenze kann wieder gesetzt werden: {1, 2, 5, 1 | 6, 9}
So würde es weitergehen, bis die zweite 1 bei der ersten 1 vorne angekommen ist. Damit wäre die Liste sortiert.

Die beste Laufzeit wäre n, und die schlechteste n^2.

Quelle: https://www.happycoders.eu/de/algorithmen/bubble-sort/

*/