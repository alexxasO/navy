/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Main
*/

#include "navy.h"

int sig_count[13];

void process_info(void)
{
    my_printf("PID: %d\n", getpid());
    my_printf("PPID: %d\n", getppid());
    my_printf("PGID: %d\n", getpgid(getpid()));
    sig_count[SIGUSR1];
}

void kill_it(int pid)
{
    kill(pid, SIGQUIT);
}

void get_pid(int sig, siginfo_t *siginfo, void *context)
{
    int pid = siginfo->si_pid;

    if (sig != SIGKILL) {
        my_printf("Signal %s received from\n", strsignal(sig));
    }
    sig_count[sig]++;
    my_printf("%d\n", pid);
}

void catch_sig(int sig)
{
    struct sigaction act;

    act.sa_sigaction = &get_pid;
    act.sa_flags = SA_SIGINFO;
    sigaction(sig, &act, NULL);
}

void who_sig_me(int ac, char **av)
{
    unsigned long int list_of_signal[2] = {SIGUSR1, SIGUSR2};
    struct sigaction act;

    act.sa_sigaction = &get_pid;
    act.sa_flags = SA_SIGINFO;
    for (int i = 0; i < ac - 1; i++) {
        list_of_signal[i] = my_getnbr(av[i + 1]);
        sigaction(list_of_signal[i], &act, NULL);
    }
    for (int i = 0; i < ac - 1; i++)
    while (1)
        usleep(1);
    //my_putstr("Unable to handle Killed signal");
    free(list_of_signal);
}

int main(int ac, char **av)
{
//    process_info();
//    if (ac == 2)
//    kill_it(my_getnbr(av[ac - 1]));
    if (ac > 1)
        who_sig_me(ac, av);
    return 0;
}
