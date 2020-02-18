/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** Allocate memory and copy string
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    str = my_strcpy(str, src);
    return str;
}
