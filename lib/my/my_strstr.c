/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Find a string in a string
*/

#include "../../include/my.h"

char *my_strstr(char *str, char const *to_find)
{
    int j = 0;

    for (int i = 0; i < my_strlen(str) + 1; i++) {
        if (str[i] == to_find[j] && str[i] != '\0')
            j++;
        else if (to_find[j] == '\0')
            return &str[i - j];
        else {
            i = i - j;
            j = 0;
        }
    }
    return 0;
}
