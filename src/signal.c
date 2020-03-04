/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Handle signal
*/

#include "navy.h"

void answer_player_two(int sig, siginfo_t *siginfo, UNUSED void *context)
{
    if (sig == SIGUSR2) {
        SIGNAL[1]++;
        usleep(50000);
        kill(siginfo->si_pid, SIGUSR1);
        SIGNAL[3] = siginfo->si_pid;
    }
}

void handle_result_signal(int *step, int sig)
{
    if (*step == 2 || *step == 0) {
        if (sig == SIGUSR1)
            SIGNAL[2] = 1;
        if (sig == SIGUSR2)
            SIGNAL[2] = 2;
        (*step)++;
    } else if (*step == 3 || *step == 1) {
        if (sig == SIGUSR1)
            SIGNAL[2] = SIGNAL[2] * 3;
        if (sig == SIGUSR2)
            SIGNAL[2] = SIGNAL[2] * 4;
        *step = ((*step) + 1) % 4;
    }
}

void handle_signal_player2(int sig, siginfo_t *siginfo, UNUSED void *context)
{
    static int step = 0;

    if (SIGNAL[3] != siginfo->si_pid)
        return;
    if (step == 0 && sig == SIGUSR2 && SIGNAL[0] == 0) {
        SIGNAL[2] = -2;
    }
    if (step == 0 && sig == SIGUSR2) {
        step = 1;
    } else if (step == 1 && sig == SIGUSR1) {
        step = 2;
        SIGNAL[2] = -1;
        return;
    }
    if (step == 2 || step == 3)
        handle_result_signal(&step, sig);
    if (sig == SIGUSR1)
        SIGNAL[0]++;
    else if (sig == SIGUSR2)
        SIGNAL[1]++;
}

void handle_signal_player1(int sig, siginfo_t *siginfo, UNUSED void *context)
{
    static int step = 0;

    if (SIGNAL[3] != siginfo->si_pid)
        return;
    if (step == 0 || step == 1)
        handle_result_signal(&step, sig);
    if (step == 2 && sig == SIGUSR2 && SIGNAL[0] == 0) {
        SIGNAL[2] = -2;
    }
    if (step == 2 && sig == SIGUSR2) {
        step = 3;
    } else if (step == 3 && sig == SIGUSR1) {
        step = 0;
        SIGNAL[2] = -1;
        return;
    }
    if (sig == SIGUSR1)
        SIGNAL[0]++;
    else if (sig == SIGUSR2)
        SIGNAL[1]++;
}

void set_sigaction(int player)
{
    struct sigaction act;

    if (player == 1)
        act.sa_sigaction = &handle_signal_player1;
    else if (player == 2)
        act.sa_sigaction = &handle_signal_player2;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    if (player == 0)
        act.sa_sigaction = &answer_player_two;
    sigaction(SIGUSR2, &act, NULL);
}
