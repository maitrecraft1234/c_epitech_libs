##
## EPITECH PROJECT, 2024
## /home/vj/code/vicmem/Makefile
## File description:
## makefile for cool lib
##

LIBNAME	=	$(notdir $(shell pwd))

SOURCEDIR	=	src/

TESTDIR	=	tests/tests/

PROFILEDIR	=	tests/prof/

TESTMAIN	=	tests/tests_main.c

SRC	=	$(shell find $(SOURCEDIR) -name '*.c')

TESTSSRC	=	$(shell find $(TESTDIR) -name '*.c')

PROFILESRC	=	$(shell find $(PROFILEDIR) -name '*.c')

OBJ	=	$(SRC:%.c=%.o)

NAME	=	lib$(LIBNAME).a

RM	=	rm -rf

INCLUDE	=	-I./include/

OPTI_LVL	=	-O3 -fno-builtin -march=native

CFLAGS	=	-Wpedantic -Wextra -Wall $(INCLUDE) $(OPTI_LVL)

CC	=	gcc

.PHONY: all fclean re clean profile debug tests_run

all:	$(NAME)

profile: CFLAGS += -pg
profile: re

debug: CFLAGS += -g3
debug: OPTI_LVL = -O0
debug: re

profile_bin: CFLAGS += -pg
profile_bin:	profile
	$(CC) $(PROFILESRC) -L. -l$(LIBNAME) \
	$(CFLAGS) -o $@

tests_bin: CFLAGS += -g3 --coverage
tests_bin: OPTI_LVL = -O0
tests_bin:	debug
	$(CC) $(TESTSSRC) -lcriterion -L. -l$(LIBNAME) \
	$(CFLAGS) -o $@

tests_main: CFLAGS += -g3
tests_main: OPTI_LVL = -O0
tests_main: LDFLAGS += -L. -l$(LIBNAME)
tests_main: debug
	$(CC) $(TESTMAIN)

tests_run: tests_bin
	./tests_bin

$(NAME)	:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	-find . -name "*.gc*" -delete

fclean: clean
	$(RM) $(NAME) tests_bin profile_bin gmon.out

re:	fclean all
