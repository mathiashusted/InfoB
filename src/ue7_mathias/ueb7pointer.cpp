/* Informatik B - Sommersemester 2022
Übung 06
Katharina Klost

Aufgabe zu Pointern
*/

#include <iostream>

void ref(int & alpha) { // Call-by-Reference
	std::cout << "&alpha: "<< (&alpha) << std::endl;
	std::cout << "alpha: " << (alpha) << std::endl;
	alpha++;
}

void val(int alpha) {  // Call-by-Value
	std::cout << "&alpha: " << (&alpha) << std::endl;
	std::cout << "alpha: "  << (alpha) << std::endl;
	alpha++;
}


void func1(int* alpha) {
  std::cout << "&alpha: " << (&alpha) << std::endl;
	std::cout << "alpha: "  << (alpha) << std::endl;
	alpha++;
}


void func2(int* alpha) {
  std::cout << "&alpha: " << (&alpha) << std::endl;
	std::cout << "alpha: "  << (alpha) << std::endl;
	(*alpha)++;
}

int main (){

// Zeichnen Sie Speicherbilder, die veranschaulichen Sie was hier passiert.
// Erklären Sie die entsprechenden Ausgaben.

	int a = 42;
  int b = 6;
  int* c = &a;
  int* d = &b;
	int & e = a;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
  std::cout << std::endl;
	std::cout << "&a: " << (&a) << std::endl;
	std::cout << "&b: " << (&b) << std::endl;
	std::cout << "&c: " << (&c) << std::endl;
	std::cout << "&d: " << (&d) << std::endl;
	std::cout << "&e: " << (&e) << std::endl;

  std::cout << std::endl;


	// std::cout << (*a) << std::endl; Warum geht das nicht?
	// std::cout << (*e) << std::endl; Warum geht das nicht?

	std::cout << "*c: " << (*c) << std::endl;
	std::cout << "*d: " << (*d) << std::endl;
	std::cout << std::endl;
	std::cout << "=== Skizzieren Sie den Aufbau des Speichers zu diesem Zeitpunkt ===" << std::endl;
	std::cout << std::endl;

	a = *c * *d;
	std::cout << "a: " << a << std::endl;
	*d -= 3;
	std::cout << "*d: " << (*d) << std::endl;
	b = a * b;
	std::cout << "b: " << b << std::endl;
	c = d;
	std::cout << "*c: " << (*c) << std::endl;

	std::cout << std::endl;
	std::cout << "=== Skizzieren Sie den Aufbau des Speichers zu diesem Zeitpunkt ===" << std::endl;
	std::cout << std::endl;

	b = 7;
	std::cout << "b: " << b << std::endl;
	a = *c + *d;
	std::cout << "a: " << a << std::endl;
	std::cout << "&e: " << (&e) << std::endl;
  std::cout << std::endl;
	std::cout << std::endl;


	c = &a;

	std::cout << std::endl;
	std::cout << "=== Skizzieren Sie den Aufbau des Speichers zu diesem Zeitpunkt ===" << std::endl;
	std::cout << std::endl;


	std::cout << std::endl;
	std::cout << "== Erklären Sie die folgenden Ausgaben ==" << std::endl;
	std::cout << std::endl;


	std::cout << "a: " << a << std::endl;
	std::cout << "&a: " << (&a) << std::endl;
  std::cout << "Rufe ref(a) auf" << std::endl;
	ref(a);
  std::cout << std::endl;



	std::cout << "a: " << a << std::endl;
	std::cout << "&a: " << (&a) << std::endl;
  std::cout << "Rufe val(a) auf" << std::endl;
	val(a);
  std::cout << std::endl;

	std::cout << "a: " << a << std::endl;

	std::cout << "c: " << c << std::endl;
	std::cout << "&c: " << (&c) << std::endl;
  std::cout << "Rufe func1(c) auf" << std::endl;
	func1(c);
  std::cout << std::endl;

	std::cout << "c: " << c << std::endl;
  std::cout << "&c: " << (&c) << std::endl;

  std::cout << "Rufe func2(c) auf" << std::endl;
  func2(c);
	std::cout << "c: " << c << std::endl;
  std::cout << "&c: " << (&c) << std::endl;
  std::cout << "a: " << a << std::endl;
}
