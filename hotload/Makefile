##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## make file should make the files
##

NAME = hotload_exemple

SOURCEDIR = src/

SRC = $(shell find $(SOURCEDIR)static -name '*.c')

DYN_SRC = $(shell find $(SOURCEDIR)dynamic -name '*.c')

DYN_OBJ = $(DYN_SRC:%.c=%.o)

DYN_NAME = loop

DYN = lib$(DYN_NAME).so

OBJ = $(SRC:%.c=%.o)

TESTS_BIN	=	tests_bin

TESTS_DIR	=	tests/

TESTS_SRC = $(shell find $(SOURCEDIR) $(TESTS_DIR) \
	-name '*.c' ! -name 'main.c')

TESTS_OBJ = $(TESTS_SRC:%.c=%.o)

CPPFLAGS	=	-iquote './include/'

RM ?= rm -f

OPTI_LEVEL ?= -O3 -fno-builtin -march=native

WARNINGS ?= -Wall -Wextra -Wpedantic

CFLAGS += $(WARNINGS) $(OPTI_LEVEL)

#LDFLAGS	= -L$(abspath .) -Wl,-rpath=$(abspath .) -l$(DYN_NAME)

CC = gcc

MAKE ?= make

all: $(DYN) $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) \
	$(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

$(DYN): OPTI_LEVEL = -O0
$(DYN): CFLAGS += -fPIC
$(DYN): $(DYN_OBJ)
	$(CC) -shared -o $(DYN) $(DYN_OBJ) $(CFLAGS) $(CPPFLAGS)

$(TESTS_BIN):LDFLAGS += -lcriterion
$(TESTS_BIN):CFLAGS += --coverage
$(TESTS_BIN):	fclean	$(TESTS_OBJ)
	$(CC) -o $(TESTS_BIN) $(TESTS_OBJ) \
	$(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

tests_run: tests_bin
	./$(TESTS_BIN)

clean:
	$(RM) $(OBJ) $(DYN_OBJ) $(TESTS_OBJ)

fclean: clean_api
	$(RM) $(NAME) debug san $(TESTS_BIN) $(DYN)

re: fclean all

debug: CFLAGS+=-g3
debug: EXEC_RUN=debug
debug: OPTI_LEVEL=-O0
debug: NAME=debug
debug: re
	$(MAKE) clean

hotload: OPTI_LEVEL = -O0
hotload: dynamic

san: EXEC_RUN = debug
san: CFLAGS += -fsanitize=address,leak,undefined -fno-omit-frame-pointer -g3
san: OPTI_LEVEL = -Og
san: NAME = san
san: re
	$(MAKE) clean

.PHONY : clean clean_api fclean all tests_run
