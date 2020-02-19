/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** Get a line in a file
*/

#include "../../include/get_next_line.h"

static int search_end_of_line(char *buf, int buf_length)
{
    for (int i = 0; i < buf_length; i++) {
        if (buf[i] == '\n' || buf[i] == '\0')
            return i;
    }
    return -1;
}

static char *fill_buffer_ext(char *buf, char *buf_tmp,
int *buf_len, int len_add)
{
    char *buf_inter;

    buf_inter = malloc(sizeof(char) * buf_len[0]);
    if (buf_inter == NULL)
        return NULL;
    for (int i = 0; i < buf_len[0] - 1; i++)
        buf_inter[i] = buf[i];
    buf_inter[buf_len[0] - 1] = '\0';
    free(buf);
    buf = malloc(sizeof(char) * buf_len[0] + len_add);
    if (buf == NULL)
        return NULL;
    for (int i = 0; i < buf_len[0] - 1; i++)
        buf[i] = buf_inter[i];
    for (int i = 0; i < len_add; i++)
        buf[buf_len[0] - 1 + i] = buf_tmp[i];
    buf[len_add + buf_len[0] - 1] = '\0';
    buf_len[0] += len_add;
    free(buf_inter);
    return buf;
}

static char *fill_buffer(char *buf, char *buf_tmp, int *buf_len, int end)
{
    int len_add = buf_len[1];

    if (end != -1)
        len_add = end;
    if (buf == NULL) {
        buf_len[0] += len_add;
        buf = malloc(sizeof(char) * buf_len[0]);
        if (buf == NULL)
            return NULL;
        for (int i = 0; i < len_add; i++)
            buf[i] = buf_tmp[i];
        buf[len_add] = '\0';
    } else
        buf = fill_buffer_ext(buf, buf_tmp, buf_len, len_add);
    return buf;
}

static int get_the_line(char *buf_tmp, int *buf_len, char **buf,
int *size_read)
{
    int fd = buf_len[0];
    int end = -1;

    buf_len[0] = 1;
    while (end == -1) {
        end = search_end_of_line(buf_tmp, buf_len[1]);
        *buf = fill_buffer(*buf, buf_tmp, buf_len, end);
        if (*buf == NULL)
            return -2;
        if (end == -1) {
            *size_read = read(fd, buf_tmp, READ_SIZE);
            buf_len[1] = READ_SIZE;
            buf_tmp[*size_read] = '\0';
        } else {
            buf_len[1] -= end + 1;
            break;
        }
    }
    return end;
}

char *get_next_line(int fd)
{
    static char buf_tmp[READ_SIZE + 1];
    static int buf_len[] = {1, READ_SIZE};
    char *buf = NULL;
    int end = -1;
    static int size_read = -10;

    if (size_read == -10 || buf_len[1] == 0) {
        size_read = read(fd, buf_tmp, READ_SIZE);
        buf_len[1] = READ_SIZE;
    }
    buf_len[0] = fd;
    end = get_the_line(buf_tmp, buf_len, &buf, &size_read);
    if (size_read <= 0 || buf_tmp[0] == '\0' || end == -2) {
        free(buf);
        return NULL;
    }
    for (int i = 0; i < buf_len[1]; i++)
        buf_tmp[i] = buf_tmp[i + end + 1];
    buf_tmp[buf_len[1]] = '\0';
    return buf;
}
