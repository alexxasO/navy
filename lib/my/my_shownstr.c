/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Display the character of a string
*/

#include "../../include/my.h"

static void add_zero(char c)
{
    if (c < 8)
        my_putchar('0');
    if (c < 32)
        my_putchar('0');
}

int my_shownstr(char const *str, int n)
{
    if (n > my_strlen(str))
        n = my_strlen(str);
    for (int i = 0; i < n; i++) {
        if (str[i] > 31 && str[i] < 127)
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            add_zero(str[i]);
            my_putnbr_base(str[i], "01234567");
        }
    }
    return 0;
}
