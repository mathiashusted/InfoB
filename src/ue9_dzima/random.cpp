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

#define MAX_INT 10000

// Experimenting with OOP

class Person {
private:
  string name;
  int age;
  //   int* vec;

public:
  void setName(string input_name) { name = input_name; }
  void setAge(int input_age) {
    if (age <= MAX_INT) {
      this->age = input_age;
    }
  }
  int getAge() const { return age; }
  string getName() const { return name; }
  // Constructor
  Person() { cout << "Person created: " << this << endl; }
  Person(string input_name) { this->name = input_name; }
  // Smart constructor
  Person(int input_age) : age(input_age) {}
  Person(string input_name, int input_age) : Person(input_name) {
    this->age = input_age;
  }
  //   Person(int size, int* arr) {
  //     vec = new int[size];
  //     for (int i=0; i < size, i++) vec[i] = arr[i];
  //   }
  //   Person(string input_name, int input_age) {
  //     this->name = input_name;
  //     this->age = input_age;
  //     cout << "Person created: " << this << endl;
  //   }

  // Destruktor
  ~Person() { cout << "Person deleted: " << this << endl; }
  //   ~Person() {
  //     delete this->age;
  //     delete this->name;
  //   }

  // Copy-constructor
  Person(const Person &someone) {
    cout << "Copy of " << &someone << " to " << this << endl;
    this->name = someone.name;
    this->age = someone.age;
    // vec = new int[someone.size];
    // for (int i=0; i < size; i++) vec[i] = someone.vec[i];
  }
};

void printPerson(Person &person) {
  cout << "Here is " << person.getName() << " of " << person.getAge() << " y.o."
       << endl;
}

class Properties {
public:
  Properties() {
    sp.x = sp.y = ep.x = ep.y = 0;
    width = 1;
    color = 0;
  }
  Properties(int x1, int y1, int x2, int y2) {
    sp.x = x1;
    sp.y = y1;
    ep.x = x2;
    ep.y = y2;
    width = 1;
    color = 0;
  }

  virtual ~Properties() { cout << "Properties deleted" << endl; }

  virtual void Draw(bool fl) { cout << "Properties Draw " << fl << endl; }

protected:
  struct Point {
    int x, y;
  };
  Point sp, ep;
  int width, color;
};

class Line : public Properties {
public:
  Line() : Properties() {}
  Line(int x1, int y1, int x2, int y2, int width, int color) {
    sp.x = x1;
    sp.y = y1;
    ep.x = x2;
    ep.y = y2;
    this->width = width;
    this->color = color;
  }

  ~Line() { cout << "Line deleted" << endl; }

  void draw() {
    cout << "Line from (" << sp.x << ", " << sp.y << ") to (" << ep.x << ", "
         << ep.y << ")" << endl;
  }

  virtual void Draw(bool fl) override { cout << "Line Draw " << fl << endl; }
};

class Line2 : public Line {
public:
  void ddraw() { cout << "Line2 Draw" << endl; }
};

class Rectangle : public Properties {
public:
  Rectangle() : Properties(0, 0, 0, 0) {}
  Rectangle(int x1, int y1, int x2, int y2, int width, int color) {
    sp.x = x1;
    sp.y = y1;
    ep.x = x2;
    ep.y = y2;
    this->width = width;
    this->color = color;
  }

  ~Rectangle() { cout << "Rectangle deleted" << endl; }

  void draw() {
    cout << "Rectangle from (" << sp.x << ", " << sp.y << ") to (" << ep.x
         << ", " << ep.y << ")" << endl;
  }
};

// Destructor testing

class parent {
  // private destructor
  ~parent() { cout << "destructor called" << endl; }

public:
  parent() { cout << "constructor called" << endl; }
  void destruct() { delete this; }
};

int main() {
  // Pointers gamearound
  cout << "-------------------" << endl;
  int p = 10;
  int *ptr = &p;
  cout << "Pointers:" << endl;
  cout << "p: " << p << endl;
  cout << "&p: " << &p << endl;
  cout << "ptr: " << ptr << endl;
  cout << "ptr*: " << *ptr << endl;
  cout << "&ptr: " << &ptr << endl;
  cout << "-------------------" << endl;
  cout << endl << endl;

  // Person OOP testing
  cout << "-------------------" << endl;
  Person max;
  max.setName("Maaaax");
  printPerson(max);

  Person *danila = new Person("dan", 2);
  danila->setName("Danila");
  danila->setAge(27);
  printPerson(*danila);
  cout << "-------------------" << endl;
  cout << endl << endl;

  // Copy
  cout << "-------------------" << endl;
  Person max2 = max;
  cout << &max2 << max2.getName() << endl;
  cout << "-------------------" << endl;
  cout << endl << endl;

  // Heredity
  cout << "-------------------" << endl;
  Line line(1, 2, 3, 4, 5, 6);
  Rectangle rect(1, 2, 3, 4, 5, 6);
  line.draw();
  rect.draw();

  Line2 line2;
  line2.ddraw();
  cout << "-------------------" << endl;
  cout << endl << endl;

  // Destructor
  cout << "-------------------" << endl;
  parent *par;
  par = new parent;
  // destructor called
  par->destruct();
  cout << "-------------------" << endl;
  cout << endl << endl;
  cout << "-Desctructors work-" << endl;
  cout << "-------------------" << endl;

  return 0;
}