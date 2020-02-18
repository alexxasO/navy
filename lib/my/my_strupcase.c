/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Put letter in uppercase
*/

#include "../../include/my.h"

char *my_strupcase(char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] > 96 && str[i] < 123)
            str[i] = str[i] - 32;
    return str;
}
