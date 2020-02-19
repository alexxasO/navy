/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** Header
*/

#ifndef GETNEXTLINE_H
#define GETNEXTLINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef READ_SIZE
#define READ_SIZE (2048)
#endif

char *get_next_line(int fd);

#endif
