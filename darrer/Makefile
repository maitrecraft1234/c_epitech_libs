##
## EPITECH PROJECT, 2024
## /home/vj/code/vicmem/Makefile
## File description:
## makefile for cool lib
##

SOURCEDIR	=	src/

SRC	=	$(shell find $(SOURCEDIR) -name '*.c')

OBJ	=	$(SRC:%.c=%.o)

NAME	=	libdarrer.a

RM	=	rm -rf

INCLUDE	=	-I./include/

OPTI_LVL	=	-O1

CFLAGS	=	-Wpedantic -Wextra -Wall $(INCLUDE) $(OPTI_LVL)

CC	=	gcc

.PHONY: all fclean re clean

all:	$(NAME)

debug: CFLAGS += -g3
debug: OPTI_LVL = -O0
debug: re

tests_bin:	debug
	$(CC) tests/main.c -L. -ldarrer \
	$(CFLAGS) -g3 -o $@ -O0

$(NAME)	:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) tests_bin

fclean: clean
	$(RM) $(NAME)

re:	fclean all
