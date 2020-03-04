/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** global_function.c
*/

#include "navy.h"

void wait_and_kill(int sig)
{
    usleep(50000);
    kill(SIGNAL[3], sig);
}