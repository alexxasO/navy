/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Handle signal
*/

#include "navy.h"

void answer_player_two(int sig, siginfo_t *siginfo, void *context)
{
    if (sig == SIGUSR2) {
        SIGNAL[1]++;
        kill(siginfo->si_pid, SIGUSR1);
    }
}

void handle_signal(int sig, siginfo_t *siginfo, UNUSED void *context)
{
    static int boolean = 0;

    if (boolean == 0 && sig == SIGUSR2)
        boolean = 1;
    if (boolean == 1 && sig == SIGUSR1) {
        boolean = 0;
        SIGNAL[2] = 1;
    }
    if (sig == SIGUSR1)
        SIGNAL[0]++;
    else if (sig == SIGUSR2)
        SIGNAL[1]++;
}

void set_sigaction(int player)
{
    struct sigaction act;

    act.sa_sigaction = &handle_signal;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    if (player == 0) {
        act.sa_sigaction = &answer_player_two;
    }
    sigaction(SIGUSR2, &act, NULL);
}
