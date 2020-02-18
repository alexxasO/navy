/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Count the lenght of a string
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
    int lenght = 0;

    for (lenght = 0; str[lenght] != '\0'; lenght++);
    return lenght;
}
