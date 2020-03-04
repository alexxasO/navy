/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Handle attack
*/

#include "navy.h"

static int check_attack_args(char *str, int readsize, int **enemy_map)
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

static int send_sig(int line, int col)
{
    int status = 0;

    for (int i = 0; i <= line; i++) {
        kill(SIGNAL[3], SIGUSR1);
        usleep(10000);
    }
    for (int i = 0; i <= col; i++) {
        kill(SIGNAL[3], SIGUSR2);
        usleep(10000);
    }
    status = kill(SIGNAL[3], SIGUSR1);
    return status;
}

int receive_response_outgoing(int **enemy_map, char *kaboum, int line, int col)
{
    while (SIGNAL[2] < 3)
        usleep(1);
    if (SIGNAL[2] == 3) {
        enemy_map[line][col] = 1;
        my_printf("%s: hit\n", kaboum);
    }
    if (SIGNAL[2] == 6) {
        enemy_map[line][col] = 2;
        my_printf("%s: missed\n", kaboum);
    }
    if (SIGNAL[2] == 4) {
        enemy_map[line][col] = 1;
        my_printf("%s: hit\n", kaboum);
        return 0;
    }
    return -1;
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
        if (readsize == 0) {
            kill(SIGNAL[3], SIGUSR2);
            return -84;
        }
        error = check_attack_args(kaboum, readsize, enemy_map);
    }
    col = kaboum[0] - 'A';
    line = kaboum[1] - '1';
    kaboum[2] = '\0';
    if (send_sig(line, col))
        return 0;
    return receive_response_outgoing(enemy_map, kaboum, line, col);
}
