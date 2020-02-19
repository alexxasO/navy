/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Check and get the information of the map
*/

#include "navy.h"

static int **fulfill_with_zero(void)
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

int check_line(char *buf)
{
    int value = 0;

    if (my_strlen(buf) != 7)
        return -1;
    value = is_char_right_num(buf[0]) + is_char_right_num(buf[3]);
    if (value + is_char_right_num(buf[6]) != 3)
        return -1;
    if (is_char_right_upper(buf[2]) + is_char_right_upper(buf[5]) != 2)
        return -1;
    if (buf[1] != ':' || buf[4] != ':')
        return -1;
    if (buf[2] != buf[5] && buf[3] != buf[6])
        return -1;
    value = buf[3] - buf[6];
    if (buf[2] == buf[5] && buf[0] - 48 != ABS(value) + 1)
        return -1;
    value = buf[2] - buf[5];
    if (buf[3] == buf[6] && buf[0] - 48 != ABS(value) + 1)
        return -1;
    return 1;
}

void replace_value_in_map(int **my_map, int x, int y, int value)
{
    if (my_map[x][y] != 0) {
        my_map[0][0] = 84;
        return;
    } else
        my_map[x][y] = value;
}

void add_boat_in_map(int **my_map, char *buf)
{
    if (buf[2] != buf[5]) {
        for (int i = buf[2] - 65; i <= buf[5] - 65; i++) {
            replace_value_in_map(my_map, buf[3] - 49, i, buf[0] - 48);
        }
    } else if (buf[3] != buf[6]) {
        for(int i = buf[3] - 49; i < buf[6] - 48; i++) {
            replace_value_in_map(my_map, i, buf[2] - 65, buf[0] - 48);
        }
    }
}

int **check_and_get_the_map(char *pathname)
{
    int **my_map = fulfill_with_zero();
    char *buf;
    int fd = open(pathname, O_RDONLY);

    if (fd == -1) {
        write(2, "The file doesn't exist\n", 23);
        my_map[0][0] = 84;
        return my_map;
    }
    buf = get_next_line(fd);
    while (buf != NULL) {
        if (check_line(buf) == -1 || my_map[0][0] == 84) {
            write(2, "The file is not correct\n", 24);
            my_map[0][0] = 84;
            return my_map;
        }
        add_boat_in_map(my_map, buf);
        buf = get_next_line(fd);
    }
    return my_map;
}
