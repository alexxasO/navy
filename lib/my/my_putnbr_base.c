/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Put a number in a given base
*/

#include "../../include/my.h"

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

int my_putnbr_base(long long int nbr, char const *base)
{
    int signe = nb_negative(nbr);
    long long int nb_origin = nbr * signe;
    int base_lenght = my_strlen(base);
    int lenght = nb_lenght(nbr, signe, base_lenght);

    nbr = nbr * signe;
    while (lenght > 0) {
        for (int i = lenght; i > 0; i--)
            nbr = nbr / base_lenght;
        lenght--;
        my_putchar(base[nbr % base_lenght]);
        nbr = nb_origin;
    }
    my_putchar(base[nbr % base_lenght]);
    return 0;
}
