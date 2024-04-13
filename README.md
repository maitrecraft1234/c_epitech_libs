# c_epitech_libs

This repository contains the C libraries that I am using for my studies at Epitech.
Everythings is written in C and is compilant with the Epitech coding style (or at least should be).

## vicmem
this lib uses gcc extensions to provide a simple and efficient memory management system.

## darrer
this lib is a dynamic array implementation. Note that it is more of a proof of concept than a real library for now.

## std
This folder contains libraries that are meant to reproduce standard C libraries.
the idea is that everything should be the same as the corresponding standard library.
execpt the nomencalture which is prefixed with `lv_` and lvi_ for
internal functions and macros.

### lv_string

This is a reproduction of the standard C library string.h.

### lv_stdlib

This is a reproduction of the standard C library stdlib.h. as of now it only has exit()
other system calls are extremely tidiuous to implement following the Epitech coding style.
However thanks to the bytecode injection I am planning on implementing malloc() and free().
in the near future.
