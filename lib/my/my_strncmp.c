/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Compare n characters of two strings
*/

#include "../../include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (n > my_strlen(s1))
        n = my_strlen(s1);
    for (int i = 0; i < n; i++)
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    return 0;
}
