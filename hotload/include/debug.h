/*
** EPITECH PROJECT, 2024
** /home/vj/code/shell/include/debug
** File description:
** debug macro
*/

#pragma once

//debug macro only expend in make debug
#ifdef DEBUG
    #include <stdio.h>
    #define DEBUG_OP __FILE__, __LINE__
    #define DB_FMT stderr, "[%s line: %d]: "
    #define DEBUGPRINT(f, ...) fprintf(DB_FMT f, DEBUG_OP, __VA_ARG__)
    #define TOKEN(a, b) a##b
    #define DEBUG_BREAK TOKEN(as, m) ("int $3")
#else
    #define DEBUGPRINT(_fmt, ...)
    #define DEBUG_BREAK
#endif
