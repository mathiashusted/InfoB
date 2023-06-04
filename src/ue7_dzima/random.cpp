#include <iostream>
using namespace std;


int main () {
    int a = 42;
    int &b = a;
    int *c = &a;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << "&a = " << &a << endl;
    cout << "&b = " << &b << endl;
    cout << "&c = " << &c << endl;

    cout << "*c = " << *c << endl;

    return 0;
}