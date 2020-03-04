/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** print_map_global.c
*/

#include "navy.h"

void print_global_map(int **player_tab, int **ennemy_tab)
{
    my_putstr("my positions:\n");
    print_playermap(player_tab);
    my_putstr("\nenemy's positions:\n");
    print_ennemymap(ennemy_tab);
    my_putstr("\n");
}