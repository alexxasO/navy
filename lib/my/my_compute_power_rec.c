/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** Power of a number with recursive
*/

#include "../../include/my.h"

static int is_negative_rec(int nb, int p)
{
    int N = 1;

    if (nb < 0 && p > 2)
        N = -1;
    return N;
}

int my_compute_power_rec(int nb, int p)
{
    int N = is_negative_rec(nb, p);
    int nb_origin = nb * N;
    int p_origin = p;
    int result = nb;

    nb = nb * N;
    if (p > 1) {
        nb = my_compute_power_rec(nb, p - 1) * nb_origin;
        if (result <= nb)
            result = nb;
        else
            return (0);
    }
    if (p == 0)
        nb = 1;
    else if (p < 0)
        nb = 0;
    if (p_origin % 2 == 1)
        nb = nb * N;
    return nb;
}
