/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Put letters in lowercase
*/

#include "../../include/my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] > 64 && str[i] < 91)
            str[i] = str[i] + 32;
    return str;
}
