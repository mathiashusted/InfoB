// Gruppe M. Husted, A. Malze, S. Kutscher
/*
Bogosort:

Bei Bogosort wird zuerst überprüft, ob eine Liste sortiert ist. Man überprüft nach jeder Sortierung die gesamte Liste.


Nun nimmt man zwei zufällig gewählte Elemente aus der Liste und tauscht sie. Dabei kann es sein, dass diese Elemente
vorher sortiert waren und man die falschen Elemente getauscht hat. Nun überprüft man wieder die gesamte Liste.
Ist sie immer noch nicht sortiert, so nimmt man wieder zwei zufälligen Elemente und tauscht sie.

So geht es immer weiter, bis die Liste durch Zufall richtig sortiert wurde. Die Laufzeit kann hierbei beliebig lang oder
kurz sein. Im schlechtesten Fall ist die Laufzeit unendlich, und im besten Fall ist sie n.

Quelle: https://sortvisualizer.com/bogosort/


*/