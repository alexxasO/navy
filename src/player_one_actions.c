/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** player_one_actions.c
*/

#include "navy.h"

static void player_one_connection(void)
{
    set_sigaction(0);
    my_putstr("waiting for enemy connection...\n\n");
    while (SIGNAL[1] == 0)
        usleep(1);
    set_sigaction(1);
    my_putstr("enemy connected\n\n");
    SIGNAL[1] = 0;
}

int player_one_actions(char **av, int **my_map, int **enemy_map)
{
    int end = -1;

    my_map = check_and_get_the_map(av[1]);
    if (my_map[0][0] == 84)
        return 84;
    player_one_connection();
    while (end == -1) {
        print_global_map(my_map, enemy_map);
        end = handle_outgoing_attack(enemy_map);
        SIGNAL[2] = 0;
        if (end != -1)
            break;
        end = handle_incoming_attack(my_map);
        if (end == -84)
            return -end;
    }
    if (end == 0)
        my_putchar('\n');
    return print_end_message(end, my_map, enemy_map);
}