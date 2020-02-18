/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** Main
*/

#include "navy.h"

void process_info(void)
{
    my_printf("PID: %d\n", getpid());
    my_printf("PPID: %d\n", getppid());
    my_printf("PGID: %d\n", getpgid(getpid()));
}

void kill_it(int pid)
{
    kill(pid, SIGQUIT);
}

void catch_sig(int sig)
{
    struct sigaction *act = malloc(sizeof(*act));
    struct sigaction *oldact = malloc(sizeof(*oldact));
    siginfo_t *siginfo = malloc(sizeof(*siginfo));
    ucontext_t *context = malloc(sizeof(*context));

    if (sig != SIGKILL) {
        printf("PREPLOUF\n");
        my_printf("Signal %s received from\n", strsignal(sig));
        printf("AFTERPLOUF\n");
    }
    printf("POSTPLOUF\n");
    sigaction(sig, act, oldact);
    printf("POSTPOSTPLOUF\n");
    printf("ACT = %d\n", act->sa_flags);
    getcontext(context);
    act->sa_sigaction(sig, siginfo, context);
    printf("POSTPOSTPOSTPLOUF\n");
    //my_printf("PID = %d\n", siginfo.si_pid);
    free(siginfo);
    free(context);
    free(act);
}

void who_sig_me(int ac, char **av)
{
    unsigned long int *list_of_signal = malloc(sizeof(unsigned long int) * (ac - 1));

    for (int i = 0; i < ac - 1; i++)
        list_of_signal[i] = my_getnbr(av[i + 1]);
    for (int i = 0; i < ac - 1; i++)
        signal(list_of_signal[i], catch_sig);
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
