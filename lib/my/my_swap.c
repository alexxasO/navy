/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Swap two integers
*/

#include "../../include/my.h"

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
