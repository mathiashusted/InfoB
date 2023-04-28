SHELL = /bin/bash
@echo -e
@echo -e "\tmake compile [arg=<test_object>]               -- run all django tests or specify module/class/function"
@echo -e
endef

# Argument passed from commandline.
arg =


.PHONY: compile
compile:
	g++ -std=c++14 -Wall -Wextra -Werror -pedantic $(arg).cpp -o $(arg)
