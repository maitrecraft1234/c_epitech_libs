##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## make file should make the files
##

NAME = PROGRAM_NAME

SOURCEDIR = src/

SRC = $(shell find $(SOURCEDIR) -name '*.c')

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

LDFLAGS	= -L./$(LIBPATH) \
	$(shell find $(LIBPATH) -maxdepth 1 -mindepth 1 -type d -printf "-l%f")

LIBPATH = lib

CC = gcc

MAKE ?= make

EXEC_RUN = all

EXEC_RULE = find $(LIBPATH) -maxdepth 1 -mindepth 1 -type d -exec $(MAKE) -C {}

all: $(NAME)

lib_exec:
	$(EXEC_RULE) $(EXEC_RUN) ';'
	find $(LIBPATH) -maxdepth 2 -mindepth 2 -name "*.a" \
	-exec cp {} $(LIBPATH)/ ';'
	find $(LIBPATH) -maxdepth 3 -mindepth 3 -name "*.h" -exec cp {} \
	./include ';'

$(NAME):	lib_exec	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) \
	$(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

clean: clean_api
	$(EXEC_RULE) clean ';'

$(TESTS_BIN):LDFLAGS += -lcriterion
$(TESTS_BIN):CFLAGS += --coverage
$(TESTS_BIN):	fclean	lib_exec	$(TESTS_OBJ)
	$(CC) -o $(TESTS_BIN) $(TESTS_OBJ) \
	$(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

tests_run: tests_bin
	./$(TESTS_BIN)

clean_api:
	$(RM) $(OBJ)
	$(RM) *~ vgcore*
	$(RM) lib/*.a
	find -name "*.gc*" -delete

fclean: clean_api
	$(EXEC_RULE) fclean ';'
	$(RM) $(NAME) debug san $(TESTS_BIN)

re: fclean all

debug: CFLAGS+=-g3
debug: EXEC_RUN=debug
debug: OPTI_LEVEL=-Og
debug: NAME=debug
debug: re
	$(MAKE) clean

san: EXEC_RUN = debug
san: CFLAGS += -fsanitize=address,leak,undefined -fno-omit-frame-pointer -g3
san: OPTI_LEVEL = -Og
san: NAME = san
san: re
	$(MAKE) clean

.PHONY : clean clean_api fclean all lib_exec tests_run
