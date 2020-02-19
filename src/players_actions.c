/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** List of the actions of each players
*/

#include "navy.h"

static int print_end_message(int end)
{
    if (end == 0)
        my_putstr("I won\n");
    else if (end == 1)
        my_putstr("Enemy won\n");
    return end;
}

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
        print_global_map(my_map, enemy_map);
        end = handle_outgoing_attack(enemy_map);
        if (end != -1)
            break;
        end = handle_incoming_attack(my_map);
    }
    return print_end_message(end);
}

static void player_two_connection(char **av)
{
    kill(my_getnbr(av[1]), SIGUSR2);
    set_sigaction(2);
    while (SIGNAL[0] == 0)
        usleep(1);
    my_putstr("successfully connected\n\n");
    SIGNAL[0] = 0;
}

int player_two_actions(char **av, int **my_map, int **enemy_map)
{
    int end = -1;

    my_map = check_and_get_the_map(av[2]);
    if (is_str_num(av[1]) == -1) {
        write(2, "The first argument is not a number\n", 35);
        return 84;
    }
    if (my_map[0][0] == 84)
        return 84;
    SIGNAL[3] = my_getnbr(av[1]);
    player_two_connection(av);
    while (end == -1) {
        print_global_map(my_map, enemy_map);
        end = handle_incoming_attack(my_map);
        if (end != -1)
            break;
        end = handle_outgoing_attack(enemy_map);
    }
    return print_end_message(end);
}
