/*
** EPITECH PROJECT, 2020
** action .c
** File description:
** action
*/

#include "navy.h"

void action(int signo, siginfo_t *si, void *data)
{
    sig = si->si_pid;
}

void action2(int signo, siginfo_t *si, void *data)
{
    sig += 1;
}

void action3(int signo, siginfo_t *si, void *data)
{
    sig = 15;
}