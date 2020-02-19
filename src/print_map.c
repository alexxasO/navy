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
    return '*';
}

static char *get_player_line(int *player_line)
{
    char *str = malloc(sizeof(char) * 15 + 1);
    int pos = 0;
    int i = 0;

    for (; i < 16; i++) {
        if (i % 2 == 0) {
            str[i] = ' ';
            continue;
        }
        if (player_line[pos] == 0)
            str[i] = '.';
        if (player_line[pos] > 0)
            str[i] = player_line[pos] + '0';
        if (player_line[pos] < 0)
            str[i] = get_missed_or_touched_char(player_line[pos]);
        pos++;
    }
    str[i] = '\0';
    return str;
}

static char *get_ennemy_line(int *player_line)
{
    char *str = malloc(sizeof(char) * 15 + 1);
    int pos = 0;
    int i = 0;

    for (; i < 16; i++) {
        if (i % 2 == 0) {
            str[i] = ' ';
            continue;
        }
        if (player_line[pos] == 0)
            str[i] = '.';
        if (player_line[pos] == 1)
            str[i] = 'o';
        if (player_line[pos] == 2)
            str[i] = 'x';
        pos++;
    }
    str[i] = '\0';
    return str;
}

void print_ennemymap(int **ennemy_tab)
{
    int line = 0;

    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (; line < 8; line++) {
        my_printf("%d|%s\n", line + 1, get_ennemy_line(ennemy_tab[line]));
    }
}

void print_playermap(int **player_tab)
{
    int line = 0;

    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (; line < 8; line++) {
        my_printf("%d|%s\n", line + 1, get_player_line(player_tab[line]));
    }
}