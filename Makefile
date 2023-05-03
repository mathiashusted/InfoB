SHELL = /bin/bash

define USAGE=
@echo -e
@echo -e "Usage:"
@echo -e "\tmake compile [arg=<test_object>]               -- compile file with specified args"
@echo -e "\tmake format [arg=<test_object>]               -- format file with clang-format"
@echo -e
endef

# Argument passed from commandline.
arg =


.PHONY: compile
compile:
	g++ -std=c++14 -Wall -Wextra -Werror -pedantic $(arg).cpp -o $(arg)


.PHONY: format
format:
	clang-format -i $(arg).cpp


.PHONY: usage
usage:
	$(USAGE)
