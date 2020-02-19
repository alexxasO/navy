/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** List of the actions of each players
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
    player_one_connection();
    while (end == 0) {
        //PRINT MAP
        //ATTACK
        //CHECK_END
        //WAIT ENEMY ATTACK
        //CHECK END
    }
    return 0;
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
    if (is_str_num(av[0]) == -1) {
        write(2, "The first argument is not a number\n", 35);
        return 84;
    }
    player_two_connection(av);
    while (end == -1) {
        //PRINT MAP
        //WAIT ENEMY ATTACK
        //CHECK_END
        //ATTACK
        //CHECK END
    }
    return 0;
}
