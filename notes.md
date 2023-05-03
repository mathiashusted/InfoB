## Code for execution:
g++ -std=c++14 -Wall -Wextra -Werror -pedantic ueb1.cpp -o ueb1

## Gitignore lines for binaries
*
!/**/
!*.*


## Example Makefile
```
SHELL = /bin/bash
define USAGE=
@echo -e
@echo -e "Usage:"
@echo -e "\tmake compile [arg=<test_object>]               -- run all django tests or specify module/class/function"
@echo -e
endef

# Argument passed from commandline.
arg =


.PHONY: compile
compile:
    g++ -std=c++14 -Wall -Wextra -Werror -pedantic $(arg).cpp -o $(arg)


.PHONY: usage
usage:
    $(USAGE)
```

### Some possible usage:
```
gromdimon@gromdimon-Latitude-7430:~/Working/InfoB$ cd ue2
gromdimon@gromdimon-Latitude-7430:~/Working/InfoB/ue2$ ls
aufgabe1_a  aufgabe1_a.cpp  aufgabe1_b  aufgabe1_b.cpp  aufgabe1_c  aufgabe1_c.cpp  aufgabe2_a  aufgabe2_a.cpp  aufgabe2_b  aufgabe2_b.cpp
gromdimon@gromdimon-Latitude-7430:~/Working/InfoB/ue2$ make compile arg='aufgabe_1a'
make: *** No rule to make target 'compile'.  Stop.
```
