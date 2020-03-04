/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Check and get the information of the map
*/

#include "navy.h"

static int check_line(char *buf)
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

static void replace_value_in_map(int **my_map, int x, int y, int value)
{
    if (my_map[x][y] != 0) {
        my_map[0][0] = 84;
        return;
    } else
        my_map[x][y] = value;
}

static void add_boat_in_map(int **my_map, char *buf)
{
    if (buf[2] != buf[5]) {
        for (int i = buf[2] - 65; i <= buf[5] - 65; i++) {
            replace_value_in_map(my_map, buf[3] - 49, i, buf[0] - 48);
        }
    } else if (buf[3] != buf[6]) {
        for (int i = buf[3] - 49; i < buf[6] - 48; i++) {
            replace_value_in_map(my_map, i, buf[2] - 65, buf[0] - 48);
        }
    }
}

static int **check_boat(int *boat_sum, int **my_map)
{
    int size = 2;

    for (int i = 0; i < 4; i++) {
        if (boat_sum[i] != size && i == 3)
            return return_error("The file is not correct\n", my_map);
        else if (boat_sum[i] == size) {
            size++;
            i = -1;
        }
        if (size == 6)
            break;
    }
    return my_map;
}

int **check_and_get_the_map(char *pathname)
{
    int **my_map = fulfill_with_zero();
    char *buf;
    int fd = open(pathname, O_RDONLY);
    int boat_sum[] = {-1, -1, -1, -1};
    int i = 0;

    if (fd == -1)
        return return_error("The file doesn't exist\n", my_map);
    buf = get_next_line(fd);
    while (buf != NULL) {
        if (check_line(buf) == -1 || my_map[0][0] == 84 || i > 3)
            return return_error("The file is not correct\n", my_map);
        boat_sum[i++] = my_getnbr(buf);
        add_boat_in_map(my_map, buf);
        buf = get_next_line(fd);
    }
    return check_boat(boat_sum, my_map);
}
