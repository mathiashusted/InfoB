#include <iostream>
#include <string>

using namespace std;

class Person{
private:
  string name;
  int alter;
public:
    Person(string name, int alter) {
      this->name = name;
      this->alter = alter;
    }
  void ausgeben(string text){
    cout << text << endl;
    cout << "Name: " << this->name << endl;
    cout << "Alter: " << this->alter << endl;

    if (text == "adressse"){
      cout << "Adresse: " << text << endl;
    }
  }
  int get_alter(){
    this->ausgeben("Adresse von p1");
    return this->alter;
  }
};

int main() {
    Person p1("Hans", 20);
    p1.ausgeben("adressse");
    cout << "---------------" << endl;
    cout << p1.get_alter() << endl;
    
    return 0;
}