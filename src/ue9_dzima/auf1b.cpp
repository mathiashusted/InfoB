/*
gromdimon
16.06.2023
*/

//**********************************************************************************************
// Aufgabe 1b

#include <iostream>
#include <string>
using namespace std;

class Tier {
private:
  string name;
  int alter;
  string gattung;

public:
  // Konstruktoren
  Tier(string name, int alter, string gattung)
      : name(name), alter(alter), gattung(gattung) {}
  Tier() : name(""), alter(0), gattung("") {}
  // Destruktor
  virtual ~Tier() { cout << "Tier " << name << " wird zerstört" << endl; }
  // Methoden
  virtual void fortbewegen() const { cout << "Ich bewege mich" << endl; }
  virtual void atmen() const { cout << "Ich atme" << endl; }
  virtual void essen() const { cout << "Ich esse" << endl; }
  virtual void anbellen(Tier t) const {
    cout << "Ich belle " << t.getName() << " an" << endl;
  }
  virtual void fortpflanzen(Tier t) const {
    cout << "Ich pflanze mich mit " << t.getName() << " fort" << endl;
  }
  string getName() const { return name; }
  int getAlter() const { return alter; }
  string getGattung() const { return gattung; }
  void setName(string name) { this->name = name; }
  void setAlter(int alter) { this->alter = alter; }
  void setGattung(string gattung) { this->gattung = gattung; }
  virtual void show() const {
    cout << "Name: " << name << endl;
    cout << "Alter: " << alter << endl;
    cout << "Gattung: " << gattung << endl;
  }
};

class Saeugetier : public Tier {
private:
  double gewicht;
  double groesse;

public:
  // Konstruktoren
  Saeugetier(double gewicht, double groesse)
      : gewicht(gewicht), groesse(groesse) {}
  Saeugetier() : gewicht(0), groesse(0) {}
  // Destruktor
  virtual ~Saeugetier() { cout << "Saeugetier wird zerstört" << endl; }
  // Methoden
  virtual void show() const {
    Tier::show();
    cout << "Gewicht: " << gewicht << endl;
    cout << "Größe: " << groesse << endl;
  }
  double getGewicht() const { return gewicht; }
  double getGroesse() const { return groesse; }
  void setGewicht(double gewicht) { this->gewicht = gewicht; }
  void setGroesse(double groesse) { this->groesse = groesse; }
};

class Hund : public Saeugetier {
private:
  string rasse;

public:
  // Konstruktoren
  Hund(string rasse) : rasse(rasse) {}
  Hund() : rasse("") {}
  // Destruktor
  virtual ~Hund() { cout << "Hund wird zerstört" << endl; }
  // Methoden
  virtual void show() const {
    Saeugetier::show();
    cout << "Rasse: " << rasse << endl;
  }
  string getRasse() const { return rasse; }
  void setRasse(string rasse) { this->rasse = rasse; }
};

class Pudel : public Hund {
private:
  string farbe;

public:
  // Konstruktoren
  Pudel(string farbe) : farbe(farbe) {}
  Pudel() : farbe("") {}
  // Destruktor
  virtual ~Pudel() { cout << "Pudel wird zerstört" << endl; }
  // Methoden
  virtual void show() const {
    Hund::show();
    cout << "Farbe: " << farbe << endl;
  }
  string getFarbe() const { return farbe; }
  void setFarbe(string farbe) { this->farbe = farbe; }
};

int main() {
  Tier t1("Tier1", 1, "Gattung1");
  Saeugetier s1(1, 1);
  Hund h1("Rasse1");
  Pudel p1("Farbe1");

  t1.show();
  cout << endl;
  s1.show();
  cout << endl;
  h1.show();
  cout << endl;
  p1.show();
  cout << endl;

  return 0;
}