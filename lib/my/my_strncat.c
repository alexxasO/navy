/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** Concatenate n characters
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int lenght = my_strlen(dest);

    if (nb <= my_strlen(src))
        nb = nb;
    else
        nb = my_strlen(src);
        for (int i = 0; i < nb + 1; i++)
            dest[lenght + i] = src[i];
    dest[lenght + nb] = '\0';
    return dest;
}
