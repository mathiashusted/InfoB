/* Gruppe M. Husted, A. Malze, S. Kutscher

Wir haben als Rückgabetyp für sowohl a) als auch b) void gewählt.

Der Grund dafür, ist dass die Funktion direkt über einen Zeiger den String manipuliert, anstatt einen neuen String zurückzugeben.
Wir können die Adresse vom String so direkt als Parameter übergeben.
Wenn wir einen string als Rückgabetyp gehabt hätten, hätten wir im Arbeitsspeicher einen neuen String erzeugt und somit
doppelt so viel Speicherplatz verbraucht. Indem wir bei einer Variable bleiben, bleibt der Code übersichtlich und effizient.


*/