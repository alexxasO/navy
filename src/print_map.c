/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** print_map.c
*/

#include "navy.h"

static char get_missed_or_touched_char(int id)
{
    if (id == -1)
        return 'o';
    if (id == -2)
        return 'x';
}

static char *get_player_line(int line, int *player_line)
{
    char str[15];
    int len = 0;

    while(player_line[len])
        len++;
    for (int i = 0; i < len; i++) {
        if (player_line[i] == 0)
            str[i] = '.';
        if (player_line[i] > 0)
            str[i] = player_line[i];
        if (player_line[i] < 0)
            str[i] = get_missed_or_touched_char(player_line[i]);
    }
    return str;
}

static char *get_ennemy_line(int line, int *player_line)
{
    char str[15];
    int len = 0;

    while(player_line[len])
        len++;
    for (int i = 0; i < len; i++) {
        if (player_line[i] == 0)
            str[i] = '.';
        if (player_line[i] == 1)
            str[i] = 'o';
        if (player_line[i] == 2)
            str[i] = 'x';
    }
    return str;
}

void print_ennemymap(int **ennemy_tab)
{
    int line = 0;

    my_putstr(" |A B C D E F G H");
    my_putstr("-+---------------");
    for (; line < 8; line++) {
        my_printf("%d|%s", line + 1, get_ennemy_line(line, ennemy_tab[line]));
    }
}

void print_playermap(int **player_tab)
{
    int line = 0;

    my_putstr(" |A B C D E F G H");
    my_putstr("-+---------------");
    for (; line < 8; line++) {
        my_printf("%d|%s", line + 1, get_player_line(line, player_tab[line]));
    }
}