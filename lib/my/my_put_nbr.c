/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** Print a nbr
*/

#include "../../include/my.h"

static int is_nb_negative(long long int nb)
{
    if (nb < 0) {
        my_putchar('-');
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

int my_put_nbr(long long int nb)
{
    int signe = is_nb_negative(nb);
    long long int nb_origin = nb * signe;
    int lenght = get_nb_lenght(nb, signe);

    nb = nb * signe;
    while (lenght > 0) {
        for (int i = lenght; i > 0; i--)
            nb = nb / 10;
        lenght--;
        my_putchar((nb % 10) + 48);
        nb = nb_origin;
    }
    my_putchar((nb % 10) + 48);
    return 0;
}
