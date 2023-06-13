/*
gromdimon
13.06.2023
*/

//**********************************************************************************************
// Some random code

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// int mult(int a, int b) {
//   return a * b;
// }

// double mult(double a, double b) {
//   return a * b;
// }

template <typename T1, typename T2>
T1 mult(T1 a, T2 b) { // If T2 at the beginning -> double mult(int a, double b)
                      // would be called
  return a * b;
}

// Templates of classes

template <typename T> class Point {
public:
  Point(T x, T y) : x(x), y(y) {}
  // Alternative:
  // Point(T x, T y) { this->x = x; this->y = y; }
  T getX() const { return x; }
  T getY() const { return y; }

  void show() const {
    cout << "(" << x << ", " << y << ")" << endl;
    cout << "Type of x: " << typeid(x).name() << endl;
    cout << "Type of y: " << typeid(y).name() << endl;
  }

private:
  T x, y;
};

// Special case: Point<string>
template <> class Point<string> {
public:
  Point(string x, string y) : x(x), y(y) {}
  string getX() const { return x; }
  string getY() const { return y; }

  void show() const {
    cout << x << ", " << y << endl;
    cout << "Type of x: " << typeid(x).name() << endl;
    cout << "Type of y: " << typeid(y).name() << endl;
  }

private:
  string x, y;
};

template <typename T> class Point3D : public Point<T> {
public:
  Point3D(T x, T y, T z) : Point<T>(x, y) { this->z = z; }
  int getZ() const { return z; }

  void show() const { cout << "Type of z: " << typeid(z).name() << endl; }

private:
  int z;
};

int global_var = 0;
void f() {
  int global_var = 1;
  cout << global_var << endl;
  cout << ::global_var << endl;
}

namespace my_namespace {
int global_var = 2;
void f() {
  int global_var = 4;
  cout << global_var << endl;
  cout << ::global_var << endl;
  cout << my_namespace::global_var << endl;
}
namespace my_namespace2 {
int global_var = 5;
void f() { cout << "just global_var " << global_var << endl; }
} // namespace my_namespace2
} // namespace my_namespace

int main() {
  cout << mult(2, 3) << endl;
  cout << mult(2.0, 3.0) << endl;

  Point<int> pt1(1, 2); // int is obligatory
  pt1.show();
  Point<string> pt2("Hello", "World");
  pt2.show();
  Point3D<double> pt3(1, 2, 3);
  pt3.show();

  // Global variables
  cout << "----------------" << endl;
  int global_var = 3;
  cout << global_var << endl;
  cout << ::global_var << endl;
  cout << "my_namespace::global_var" << endl;
  f();
  my_namespace::f();
  cout << "my_namespace::my_namespace2::global_var" << endl;
  my_namespace::my_namespace2::f();

  return 0;
}