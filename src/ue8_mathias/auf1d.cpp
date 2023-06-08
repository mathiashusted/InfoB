// Gruppe M. Husted, A. Malze, S. Kutscher

/*
Wir betrachten die folgende Klasse, die den Anfang einer Implementierung eines Binärbaums enthält.
Die Größe des Binarbaums wird beim Aufruf des Konstruktors definiert, und genau so viel
Speicherplatz wird dann im Heap reserviert. Dieser muss am Ende (Destruktor) wieder freigegeben
werden. Passiert das nicht, bleibt der Speicherplatz für den Binärbaum reserviert, obwohl er nicht mehr gebraucht wird.

Zudem muss ein Copy Konstruktor deklariert werden, damit im Falle einer Kopie das Verhalten bestimmt werden kann, und
ggf. Speicherplatz alloziert werden kann.

Beim Copy-Assignment-Operator geht es vor allem darum, nach dem Kopievorgang den alten Speicherplatz wieder freizugeben.
*/
class binTree {
    private:
        int* tree;
        int size;
        int position;
    public:
        binTree(int size) {
            this -> tree = new int(size);
            this -> size = size;
            this -> position = 0;
        }
        binTree(const binTree & argTree) {
            this -> tree = new int(argTree.size);
            this -> size = argTree.size;
            this -> position = argTree.position;

            for (int i = 0; i < this->size; i++) {
                this -> tree[i] = argTree.tree[i];
            }
        }
        binTree& operator=(const binTree & argTree) {
            if (this != &argTree) {

                delete[] tree;

                this->tree = new int(argTree.size);
                this->position = argTree.position;
                this->size = argTree.size;

                for (int i = 0; i < this->size; i++) {
                    this -> tree[i] = argTree.tree[i];
                }
            }
            return *this;
        }
        ~binTree() {
            delete tree;
            position = 0;
            size = 0;
        }
};

int main() {

}