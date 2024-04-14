/*
** EPITECH PROJECT, 2024
** include/lvstrings
** File description:
** lvs header
*/

#pragma once

#include <stddef.h>

/*
 * In case you want the strdup and strconcat allocator
 * to be something other than malloc. Don't forget to modify
 * the DEALLOCATOR as WELL as it could break the STRDUPA.
 * I recommend simply defining the ALLOCTOR and DEALLOCATOR
 * right under this comment but you can also modify the current
 * definition.
 */
#ifndef ALLOCATOR
    #include <malloc.h>
    #define ALLOCATOR(s) malloc(s)
#endif

#ifndef DEALLOCATOR
    #include <malloc.h>
    #define DEALLOCATOR(p) free(p)
#endif

/*
 * STRDUPA depends on a gcc extention, gcc or clang isn't detected
 * it will simply memory leak but it should still work fine.
 */
#ifdef __GNUC__
static inline void lvi_string_free(char **pt)
{
    DEALLOCATOR(*pt);
}
    #define LVI_CLEAN __attribute__((cleanup(lvi_string_free)))
#else
    #define LVI_CLEAN
    #warning STRDUPA requires gcc or clang, the memory will no be freed
#endif

#define LV_STRDUPA(name, dup) char *name LVI_CLEAN = lvs_strdup(dup)

/*
 * these two function will copy n bytes from source to dest.
 *
 * memcpy is used if the dest and source pointers are different
 * otherwise memove should be used.
 */
void *lv_memcpy(
    void *restrict dest,
    const void *restrict source,
    size_t n);
void *lv_memmove(
    void *dest,
    const void *source,
    size_t n);

/*
 * sets n bytes of dest into value
 */
void *lv_memset(
    void *restrict dest,
    int value,
    size_t n);

/*
 * compares n bytes of s1 and s2, returns the difference between the
 * first 2 different bytes value or 0 if all bytes are the same.
 */
int lv_memcmp(const void *s1, const void *s2, size_t n);

/*
 * returns a pointer to the first occurence of search byte within buffer and
 * buffer + n, returns NULL if no occurence is found.
 */
void *lv_memchr(const void *buffer, int search, size_t n);

/*
 * returns len of string.
 */
size_t lv_strlen(char const *string);

/*
 * returns a pointer to a heap allocated string identicall to the one provided.
 * strndup will return a null terminated string with n characters that will
 * be identicall to the n first characters of the string passed as argument.
 */
char *lv_strdup(const char *string);
char *lv_strndup(const char *string, size_t n);

/*
 * returns a pointer to next occurence of a character within delim.
 * call with the string the first time, NULL to get the next one.
 */
char *lv_strtok(char *string, const char *delim);
char *lv_strtok_r(char *string, const char *delim, char **save);

/*
 * copies src at the end of dest, if dest isn't large enough it will
 * result in undefined behavior. strncat will copy n characters instead
 * of the whole src string.
 */
char *lv_strcat(char *dest, const char *src);
char *lv_strncat(char *dest, const char *src, size_t n);

/*
 * returns a pointer to the first occurence of search character in string.
 * strrchr starts the search at the end.
 */
char *lv_strchr(const char *string, int search);
char *lv_strrchr(const char *string, int search);

/*
 * will returns the lenght of the string containing only accept characters
 * and not containg reject character for strcspn.
 */
size_t lv_strspn(const char *string, const char *accept);
size_t lv_strcspn(const char *string, const char *reject);

/*
 * returns a pointer to the first occurence of the needle string in the
 * haystack string. NULL if needle is not found.
 */
char *lv_strstr(const char *haystack, const char *needle);
