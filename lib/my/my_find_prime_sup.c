/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** Find the next prime
*/

#include "../../include/my.h"

int my_find_prime_sup(int nb)
{
    int prime = my_is_prime(nb);

    for (nb = nb; prime != 1; nb++)
        prime = my_is_prime(nb);
    return nb;
}
