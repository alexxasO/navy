/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Compare two string
*/

#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; i < my_strlen(s1) + 1; i++)
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    return 0;
}
