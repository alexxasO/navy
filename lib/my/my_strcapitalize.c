/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Put the first letter of each word in uppercase
*/

#include "../../include/my.h"

static int is_low(char letter)
{
    if (letter > 96 && letter < 123)
        return 1;
    return 0;
}

static int is_let(char letter)
{
    if (letter > 96 && letter < 123)
        return 1;
    else if (letter > 64 && letter < 91)
        return 1;
    return 0;
}

static int is_num(char letter)
{
    if (letter > 47 && letter < 58)
        return 1;
    else if (is_let(letter) == 1)
        return 1;
    return 0;
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (is_num(str[i - 1]) == 0 && is_low(str[i]) == 1)
            str[i] -= 32;
        else if (str[i] > 64 && str[i] < 91 && is_num(str[i - 1]) == 1)
            str[i] += 32;
    return str;
}
