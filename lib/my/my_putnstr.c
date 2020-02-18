/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Display the character of a string
*/

#include "../../include/my.h"

int my_putnstr(char const *str, int n)
{
    if (n > my_strlen(str))
        n = my_strlen(str);
    for (int i = 0; i < n; i++) {
        if (str[i] > 31 && str[i] < 127)
            my_putchar(str[i]);
    }
    return 0;
}
