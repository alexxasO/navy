/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Handle attack
*/

#include "navy.h"

void handle_incoming_attack(int **my_map)
{
    int j = 0;

    while (SIGNAL[2] == 0)
        usleep(1);
    if (my_map[SIGNAL[0]][SIGNAL[1]] == 0)
        my_map[SIGNAL[0]][SIGNAL[1]] = -2;
    else
        my_map[SIGNAL[0]][SIGNAL[1]] = -1;
    for (int i = 0; i < 8; i++) {
        if (map[j][i] > 0) {
            kill(SIGNAL[3], SIGUSR1);
        }
        if (i == 7 && j != 7) {
            j++;
            i = -1;
        }
    }
}
