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

int SIGNAL[4];

int player_one_actions(char **av, int **my_map, int **enemy_map);
int player_two_actions(char **av, int **my_map, int **enemy_map);
int print_end_message(int end, int **my_map, int **enemy_map);

void answer_player_two(int sig, siginfo_t *siginfo, void *context);
void handle_signal(int sig, siginfo_t *siginfo, void *context);
void set_sigaction(int player);

int **check_and_get_the_map(char *pathname);
int **fulfill_with_zero(void);

int is_str_num(char *str);
int is_char_right_num(char c);
int is_char_right_upper(char c);
int **return_error(char *msg, int **my_map);

void print_playermap(int **player_tab);
void print_ennemymap(int **ennemy_tab);
void print_global_map(int **player_tab, int **ennemy_tab);

int handle_incoming_attack(int **my_map);
int handle_outgoing_attack(int **enemy_map);

#endif
