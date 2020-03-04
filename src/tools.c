/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Tools
*/

#include "navy.h"

int is_str_num(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] > '9' || str[i] < '0')
            return -1;
    }
    return 1;
}

int is_char_right_num(char c)
{
    if (c > '8' || c < '1')
        return -1;
    return 1;
}

int is_char_right_upper(char c)
{
    if (c > 'H' || c < 'A')
        return -1;
    return 1;
}

int **fulfill_with_zero(void)
{
    int **map = malloc(sizeof(int *) * 8);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(int) * 8);
        for (int j = 0; j < 8; j++) {
            map[i][j] = 0;
        }
    }
    return map;
}

int **return_error(char *msg, int **my_map)
{
    int length = my_strlen(msg);

    write(2, msg, length);
    my_map[0][0] = 84;
    return my_map;
}
