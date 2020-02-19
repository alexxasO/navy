/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Header for Navy
*/

#ifndef NAVY_H
#define NAVY_H

#include "my.h"
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <ucontext.h>

#define ABS(value) (((value) < (0)) ? (-value) : (value))

int SIGNAL[3];

int player_one_actions(char **av);
int player_two_actions(char **av);

void answer_player_two(int sig, siginfo_t *siginfo, void *context);
void handle_signal(int sig, siginfo_t *siginfo, void *context);
void set_sigaction(int player);

int **check_and_get_the_map(char *pathname);

int is_str_num(char *str);
int is_char_right_num(char c);
int is_char_right_upper(char c);

#endif
