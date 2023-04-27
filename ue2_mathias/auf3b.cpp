/*
3b) Es gibt in C++ noch eine weitere Schleifenart. Recherchieren Sie welche dies ist. Geben Sie die
allgemeine Form an und beschreiben Sie die Funktionalität. Denken Sie daran Quellen anzugeben.



Es exisiert in C++ noch die Do-While-Schleife.

do {
  // Codeblock
}
while (Bedingung);

Der entscheidende Unterschied bei dieser Schleifenart  zu While ist, dass der Code immer MINDESTENS ein Mal ausgeführt wird,
und die Bedingung erst danach geprüft wird. Wird also nach der ersten Ausführung bspw. festgestellt, dass die Bedingung
von vorne hinein falsch war, wird also abgebrochen. Eine normale While-Schleife hätte an dieser Stelle gar nicht erst
die Ausführung angefangen.


Quellen: https://en.cppreference.com/w/cpp/language/do, https://www.w3schools.com/cpp/cpp_do_while_loop.asp
*/