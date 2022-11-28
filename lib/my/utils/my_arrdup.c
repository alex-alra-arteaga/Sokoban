/*
** EPITECH PROJECT, 2022
** my_arrdup.c
** File description:
** my_strdup but for arrays
*/

#include "my.h"

char **my_arrdup(char **src, int size)
{
    char **str_array;
    int lines = size;
    int l = 0;

    if (src[0][0] == '\0')
        return (NULL);
    str_array = malloc(sizeof(char*) * lines + sizeof(char *));
    str_array[0] = 0;
    while (l < lines) {
        str_array[l] = my_strdup(src[l]);
        l++;
    }
    return (str_array);
}