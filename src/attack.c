/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Handle attack
*/

#include "navy.h"

int handle_incoming_attack(int **my_map)
{
    int j = 0;

    SIGNAL[0] = 0;
    SIGNAL[1] = 0;
    my_putstr("\nwaiting for ennemy's attack...\n");
    while (SIGNAL[2] == 0)
        usleep(1);
    if (my_map[SIGNAL[0] - 1][SIGNAL[1] - 1] == 0) {
        my_map[SIGNAL[0] - 1][SIGNAL[1] - 1] = -2;
        kill(SIGNAL[3], SIGUSR2);
    } else {
        my_map[SIGNAL[0] - 1][SIGNAL[1] - 1] = -1;
        kill(SIGNAL[3], SIGUSR1);
    }
    SIGNAL[0] = 0;
    SIGNAL[1] = 0;
    usleep(100);
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
    return 0;
}

static int check_attack_args(char *str, int readsize)
{
    int count = 0;

    if (readsize == 3)
        count++;
    if (str[0] >= 'A' && str[0] <= 'H')
        count++;
    if (str[1] >= '1' && str[1] <= '8')
        count++;
    if (count == 3)
        return 0;
    my_putstr("wrong position\n");
    return 1;
}

static void send_sig(int line, int col)
{
    for (int i = 0; i <= line; i++) {
        kill(SIGNAL[3], SIGUSR1);
        usleep(10000);
    }
    for (int i = 0; i <= col; i++) {
        kill(SIGNAL[3], SIGUSR2);
        usleep(10000);
    }
    kill(SIGNAL[3], SIGUSR1);
}

int handle_outgoing_attack(int **enemy_map)
{
    int col = 0;
    int line = 0;
    char kaboum[3];
    int error = 1;
    int readsize = 0;

    while (error) {
        my_putstr("attack: ");
        readsize = read(0, kaboum, 5);
        error = check_attack_args(kaboum, readsize);
    }
    col = kaboum[0] - 'A';
    line = kaboum[1] - '1';
    kaboum[2] = '\0';
    if (enemy_map[line][col] == 0)
        send_sig(line, col);
    while (SIGNAL[2] < 3)
        usleep(1);
    if (SIGNAL[2] == 3) {
        enemy_map[line][col] = 1;
        my_printf("\n%s: hit\n", kaboum);
    }
    if (SIGNAL[2] == 6) {
        enemy_map[line][col] = 2;
        my_printf("\n%s: missed\n", kaboum);
    }
    if (SIGNAL[2] == 8) {
        enemy_map[line][col] = 1;
        my_printf("\n%s: hit\n", kaboum);
        return 1;
    }
    return -1;
}
