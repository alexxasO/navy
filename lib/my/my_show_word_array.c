/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** Display an array of words
*/

#include <stdlib.h>
#include "../../include/my.h"

int  my_show_word_array(char * const *tab)
{
    char *str;
    int lenght = 0;
    int j = 0;

    for (int i = 0; tab[i]; i++)
        lenght += my_strlen(tab[i]) + 1;
    str = malloc(sizeof(char) * (lenght + 1));
    str[0] = '\0';
    for (j = 0; tab[j] != 0; j++) {
        str = my_strcat(str, tab[j]);
        str = my_strcat(str, "\n");
    }
    my_putstr(str);
    return 0;
}
