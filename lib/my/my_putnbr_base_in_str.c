/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Put a number in a given base
*/

#include "../../include/my.h"
#include <stdlib.h>

static int nb_negative(long long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        return -1;
    } else if (nb == 0)
        return 0;
    return 1;
}

static int nb_lenght(long long int nb, int signe, int base_lenght)
{
    int lenght = 0;

    nb = nb * signe;
    while (nb / base_lenght > 0) {
        lenght++;
        nb = nb / base_lenght;
    }
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

char *my_putnbr_base_in_str(long long int nbr, char const *base)
{
    int signe = nb_negative(nbr);
    long long int nb_origin = nbr * signe;
    int base_lenght = my_strlen(base);
    int lenght = nb_lenght(nbr, signe, base_lenght);
    char *nbr_in_str = alloc_mem(signe, lenght);
    int pos = 0;

    if (signe == -1) {
        pos++;
        nbr_in_str[0] = '-';
    }
    nbr = nbr * signe;
    for (lenght = lenght; lenght > 0; lenght--) {
        for (int i = lenght; i > 0; i--)
            nbr = nbr / base_lenght;
        nbr_in_str[pos++] = base[nbr % base_lenght];
        nbr = nb_origin;
    }
    nbr_in_str[pos++] = base[nbr % base_lenght];
    nbr_in_str[pos] = '\0';
    return nbr_in_str;
}
