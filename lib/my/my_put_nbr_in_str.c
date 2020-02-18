/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** Print a nbr
*/

#include "../../include/my.h"
#include <stdlib.h>

static int is_nb_negative(long long int nb)
{
    if (nb < 0) {
        return -1;
    } else if (nb == 0)
        return 0;
    return 1;
}

static int get_nb_lenght(long long int nb, int signe)
{
    int lenght = 0;

    nb = nb * signe;
    for (lenght = 0; nb / 10 > 0; lenght++)
        nb = nb / 10;
    return lenght;
}

static char *alloc_mem(int signe, int lenght)
{
    char *nbr_in_str;

    if (signe == -1)
        nbr_in_str = malloc(sizeof(char) * lenght + 3);
    else
        nbr_in_str = malloc(sizeof(char) * lenght + 2);
    return nbr_in_str;
}

char *my_put_nbr_in_str(long long int nb)
{
    int signe = is_nb_negative(nb);
    long long int nb_origin = nb * signe;
    int lenght = get_nb_lenght(nb, signe);
    char *nbr_in_str = alloc_mem(signe, lenght);
    int pos = 0;

    if (signe == -1) {
        pos++;
        nbr_in_str[0] = '-';
    }
    nb = nb * signe;
    for (lenght = lenght; lenght > 0; lenght--) {
        for (int i = lenght; i > 0; i--)
            nb = nb / 10;
        nbr_in_str[pos++] = (nb % 10) + 48;
        nb = nb_origin;
    }
    nbr_in_str[pos++] = (nb % 10) + 48;
    nbr_in_str[pos] = '\0';
    return nbr_in_str;
}
