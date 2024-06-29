##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC	=	gcc

NAME	=	tests_main

SRC	=	$(shell find ./src -name '*.c')

OBJ	=	$(SRC:%.c=%.o)

CPPFLAGS	=	-iquote ./include

CFLAGS	?=	-W -Wall -Wextra -g3 -fanalyzer



all: $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS)
	./$(NAME)

clean:
	rm -f $(OBJ) $(NAME)
