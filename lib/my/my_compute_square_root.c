/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** Square of a number
*/

#include "../../include/my.h"

int my_compute_square_root(int nb)
{
    int root = 1;
    int square = 1;

    if (nb > 0) {
        for (root = 1; square != nb && nb > square && root < 46341; root++)
            square = root * root;
        if (nb < square || root == 46341)
            return 0;
    } else
        return 0;
    return root;
}
