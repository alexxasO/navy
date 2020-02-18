/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Display the character of a string
*/

#include "../../include/my.h"
#include <stdlib.h>

static void add_zero(char c, char *str2, int pos)
{
    if (c < 8)
        str2[pos++] = '0';
    if (c < 32)
        str2[pos++] = '0';
    str2[pos] = '\0';
}

static int get_lenght(char const *str)
{
    int lenght = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 31 && str[i] < 127)
            lenght++;
        else
            lenght += 4;
    }
    return lenght;
}

char *my_showstr_in_str(char const *str)
{
    int lenght = get_lenght(str);
    char *str2;
    int pos = 0;
    char *str3;

    str2 = malloc(sizeof(char) * lenght + 1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 31 && str[i] < 127)
            str2[pos++] = str[i];
        else {
            str2[pos++] = '\\';
            add_zero(str[i], str2, pos);
            str3 = my_putnbr_base_in_str(str[i], "01234567");
            my_strcat(str2, str3);
            pos += 3;
            free(str3);
        }
    }
    str2[lenght] = '\0';
    return str2;
}
