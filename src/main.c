/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Main
*/

#include "navy.h"

void put_usage(void)
{
    my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions]\n");
    my_putstr("DESCRIPTION\n\tfirst_player_pid:\tpid of the first player");
    my_putstr(" (only for the 2nd player)\n\tnavy_positions:\t\tfile ");
    my_putstr("representing the positions of the ships\n");
}

int main(int ac, char **av)
{
    int return_value = 0;
    int **my_map = NULL;
    int **enemy_map = fulfill_with_zero();

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        put_usage();
        return 0;
    }
    if (ac == 1 || ac > 3) {
        write(2, "Wrong number of arguments\n", 26);
        return 84;
    }
    SIGNAL[0] = 0;
    SIGNAL[1] = 0;
    SIGNAL[2] = 0;
    my_printf("my_pid: %d\n", getpid());
    if (ac == 2)
        return_value = player_one_actions(av, my_map, enemy_map);
    else if (ac == 3)
        return_value = player_two_actions(av, my_map, enemy_map);
    return return_value;
}
