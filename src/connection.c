/*
** EPITECH PROJECT, 2020
** connection.c
** File description:
** connection
*/

#include "navy.h"

void connect_server(navy_t *navy)
{
    struct sigaction sa;

    put_str("waiting for enemy connection...\n\n");
    while (sig == 0);
    navy->ennemie_pid = sig;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = action2;
    sigaction(SIGUSR1, &sa, 0);
    sa.sa_sigaction = action3;
    sigaction(SIGUSR2, &sa, 0);
    put_str("enemy connected\n");
    display_maps(navy);
    sig = 0;
    kill(navy->ennemie_pid, SIGUSR1);
    usleep(100);
}

void connect_client(navy_t *navy)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = action2;
    sigaction(SIGUSR1, &sa, NULL);
    sa.sa_sigaction = action3;
    sigaction(SIGUSR2, &sa, NULL);
    kill(navy->ennemie_pid, SIGUSR1);
    usleep(100);
    while (sig == 0);
    put_str("successfully connected\n");
    sig = 0;
    display_maps(navy);
}