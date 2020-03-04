/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Handle defense
*/

#include "navy.h"

static int check_if_party_is_ended(int **my_map)
{
    int j = 0;

    for (int i = 0; i < 8; i++) {
        if (my_map[j][i] > 0) {
            kill(SIGNAL[3], SIGUSR1);
            return -1;
        }
        if (i == 7 && j != 7) {
            j++;
            i = -1;
        }
    }
    kill(SIGNAL[3], SIGUSR2);
    return 1;
}

static void reset_signal_value(void)
{
    SIGNAL[0] = 0;
    SIGNAL[1] = 0;
}

int handle_incoming_attack(int **my_map)
{
    reset_signal_value();
    my_putstr("waiting for enemy's attack...\n");
    while (SIGNAL[2] == 0)
        usleep(1);
    if (SIGNAL[2] == -2)
        return -84;
    my_printf("%c%c: ", SIGNAL[1] + 64, SIGNAL[0] + 48);
    if (my_map[SIGNAL[0] - 1][SIGNAL[1] - 1] <= 0) {
        my_map[SIGNAL[0] - 1][SIGNAL[1] - 1] = -2;
        kill(SIGNAL[3], SIGUSR2);
        my_putstr("missed\n\n");
    } else {
        my_map[SIGNAL[0] - 1][SIGNAL[1] - 1] = -1;
        kill(SIGNAL[3], SIGUSR1);
        my_putstr("hit\n\n");
    }
    reset_signal_value();
    usleep(100);
    return check_if_party_is_ended(my_map);
}
