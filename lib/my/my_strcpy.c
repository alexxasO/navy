/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Copy a string
*/

#include "../../include/my.h"

char *my_strcpy(char *dest, char const *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        dest[i] = str[i];
    dest[my_strlen(str)] = '\0';
    return dest;
}
