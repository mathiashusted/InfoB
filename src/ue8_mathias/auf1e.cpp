// Gruppe M. Husted, A. Malze, S. Kutscher

/*
Hier betrachten wir wieder die Klasse aus 1d)
Wir können eine Funktion bauen, die unseren "Cursor" verschiebt. Das übergebene Argument wird
nicht verändert, bleibt also konstant. Deswegen benutzen wir const.
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
        // Vor: Eingabe >= 0
        // Erg:
        // Eff: Position des "Cursors" wird verschoben
        void changePosition(const int & newPos) { // Die Variable newPos wird nicht verändert => const benutzen
            this -> position = newPos;
        }
};

int main() {

}