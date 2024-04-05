##
## EPITECH PROJECT, 2024
## /home/vj/code/vicmem/Makefile
## File description:
## makefile for cool lib
##

LIBNAME	=	lvstrings

SOURCEDIR	=	src/

TESTDIR	=	tests/tests/

PROFILEDIR	=	tests/prof/

SRC	=	$(shell find $(SOURCEDIR) -name '*.c')

TESTSSRC	=	$(shell find $(TESTDIR) -name '*.c')

PROFILESRC	=	$(shell find $(PROFILEDIR) -name '*.c')

OBJ	=	$(SRC:%.c=%.o)

NAME	=	lib$(LIBNAME).a

RM	=	rm -rf

INCLUDE	=	-I./include/

OPTI_LVL	=	-O3 -fno-builtin

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
