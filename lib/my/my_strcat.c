/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** Concatenate two string
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int lenght = my_strlen(dest);

    for (int i = 0; i < my_strlen(src) + 1; i++)
        dest[lenght + i] = src[i];
    dest[my_strlen(dest)] = '\0';
    return dest;
}
