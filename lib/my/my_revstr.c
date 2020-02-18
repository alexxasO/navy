/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Reverse a string
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int letter;

    for (int i = 0; i < my_strlen(str) / 2; i++) {
        letter = str[i];
        str[i] = str[my_strlen(str) - i - 1];
        str[my_strlen(str) - i - 1] = letter;
    }
    return str;
}
