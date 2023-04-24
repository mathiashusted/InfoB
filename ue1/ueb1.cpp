/*
Code aus der Datei "ueb1.cpp"
Mathias Husted, 2023
(Aufgaben wurden unten bearbeitet)
*/

#include <iostream>

int main(){
  int x = 2; // Eine ganze Zahl x wird auf 2 gesetzt
  for (int i=0; i<32; i++){ // For schleife: Variable i wird erstellt und auf 0 gesetzt -> solange i < 32 ist, mache weiter, inkrementiere jedes Mal i um 1
    x=x*2; // x wird um den Faktor 2 erhöht
  } // i existiert nur lokal innerhalb der Schleife
  std::cout << x << std::endl; // x wird ausgegeben

  int zahl = 50; // Eine neue ganze Zahl wird dem Wert 50 zugewiesen
  std::cout << (3+5*9==zahl-2) << std::endl; // Boolean wird ausgegeben (true/1, da 48==48)
  std::cout << "Info B " << (40 * zahl + 23) << std::endl; // Der String "Info B" sowie der Integer, der aus der Operation entsteht (2023) wird zusammengesetzt und ausgegeben
  std::cout << (true && (++zahl > 50)) << std::endl; // Da true && (51>50) = true, wird true ausgegeben (boolesche Algebra)
  // Die Zahl "zahl" wird um 1 inkrementiert, BEVOR sie mit der 50 verglichen wird. "zahl" bleibt nach dem Ausdruck 51
  std::cout << zahl << std::endl; // Jetzt wird der neue Wert von zahl ausgegeben (51)
  std::cout << ((zahl <= 44) + 7) << std::endl; // Der Ausdruck ergibt false, es wird 7 dazuaddiert - also wird das false ignoriert


  int y = 3; // y = 3 wird als ganze Zeit definiert
  int z = ++y + 2; // z setzt sich aus y + 2 zusammen, wobei y ZUERST inkrementiert wird, und dann 2 dazuaddiert wird. Also ergibt es 4+2=6
  std::cout << "z: " << z << std::endl; //
  std::cout << "y: " << y << std::endl; // z und y werden nacheinander ausgegeben
  z = y++ + 2; // y wird NACH dem Ausdruck inkrementiert. In der Rechenoperation steht also noch das "alte" z - z ist also 4+2=6, aber danach ist y=5
  std::cout << "z: " << z << std::endl;
  std::cout << "y: " << y << std::endl;


  short a = 345; // Neue Variable mit Datentyp Short
  std::cout << "Größe von a " << sizeof(a) << std::endl; // Die Größe im Arbeitsspeicher in Byte von der Variable a (2 Byte = 8 Bit)
  std::cout << "Größe von a+y " << sizeof(a+y) << std::endl; // Wenn a+y addiert werden, entsteht dabei ein "unsigned long" (also ein positiver Integer mit mehr Speicherplatz) (4 Byte = 16 Bit)

  std::cout << "Geben Sie eine Zahl ein: "; // Nutzer wird zur Eingabe aufgefordert
  std::cin >> a; // cin liest die Eingabe über die Tastatur
  std::cout << "Ihre Zahl ist: " << a <<std::endl; // Zahl wird wieder ausgegeben

  if(y++ == 6){ // y == 6 ist false, da y 5 ist (aber nach dem if-Statement wird y inkrementiert auf 6) der if-Block wird also übersprungen
    std::cout << "Huhu" << std::endl;
  }
  std::cout << "y: " << y << std::endl;
  if(--y == 6){ //y ist vor dem if noch 6, wird allerdings nun dekrementiert BEVOR es mit der 6 verglichen wird - also ist die Voraussetzung wieder nicht gegeben, und der if-Block wird übersprungen
    std::cout << "Hallo" << std::endl;
  }
  std::cout << "y: " << y << std::endl;

  //**********************************************************************************************
  // AUFGABE 2c
  //
  // Damit die if-Blocks zu wahr auswerten, ohne die Variablen zu verändern, müssen wir also dafür sorgen, dass y nicht inkrementiert
  // bzw. dekrementiert wird, und immer mit der 5 verglichen wird (weil y = 5 ist)

  if(y == 5){
    std::cout << "Huhu" << std::endl;
  }
  std::cout << "y: " << y << std::endl;
  if(y == 5){ 
    std::cout << "Hallo" << std::endl;
  }
  std::cout << "y: " << y << std::endl;
  // Der Code in den if-Blocks wird nun mit ausgegeben
}
