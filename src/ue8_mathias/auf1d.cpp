// Gruppe M. Husted, A. Malze, S. Kutscher

/*
Wir betrachten die folgende Klasse, die den Anfang einer Implementierung eines Binärbaums enthält.
Die Größe des Binarbaums wird beim Aufruf des Konstruktors definiert, und genau so viel
Speicherplatz wird dann im Heap reserviert. Dieser muss am Ende (Destruktor) wieder freigegeben
werden.
*/
class binTree {
    private:
        int* tree;
        int position;
    public:
        binTree(int size) {
            tree = new int(size);
            position = 0;
        }
        ~binTree() {
            tree = nullptr;
            position = 0;
        }
};