/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** String with printable characters
*/

#include "../../include/my.h"

int my_str_isprintable(char const *str)
{
    if (str[0] == '\0')
        return 1;
    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] > 31 && str[i] < 127)
            return 1;
        else
            break;
    return 0;
}
