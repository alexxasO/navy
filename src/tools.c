/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Tools
*/

#include "navy.h"

int is_str_num(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] > '9' || str[i] < '0')
            return -1;
    }
    return 1;
}

int is_char_right_num(char c)
{
    if (c > '8' || c < '1')
        return -1;
    return 1;
}

int is_char_right_upper(char c)
{
    if (c > 'H' || c < 'A')
        return -1;
    return 1;
}
