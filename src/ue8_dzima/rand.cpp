#include <iostream>
#include <string>
using namespace std;

class A {
public:
  void func1() { std ::cout << "A1" << std ::endl; }
  virtual void func2() { std ::cout << "A2" << std ::endl; }
};

class B : public A {
public:
  void func1() { std ::cout << "B1" << std ::endl; }
  void func2() { std ::cout << "B2" << std ::endl; }
};

int main() {
  A *a = new B();
  a->func1();
  a->func2();
  return 0;
}