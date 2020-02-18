/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Display the character of a string
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}
