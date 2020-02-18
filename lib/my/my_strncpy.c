/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Copy n characters of a string
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *str, int n)
{
    for (int i = 0; i < n; i++)
        if (i <= my_strlen(str))
            dest[i] = str[i];
        else
            dest[i] = '\0';
    return dest;
}
