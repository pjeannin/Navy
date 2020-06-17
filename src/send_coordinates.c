/*
** EPITECH PROJECT, 2020
** send_coordinates.
** File description:
** send_coordinates
*/

#include "navy.h"

void send_coordinates(pid_t ennemie_pid, char *read_val)
{
    usleep(100);
    for (int i = 0; i < read_val[0] - 64; ++i) {
        kill(ennemie_pid, SIGUSR1);
        usleep(100);
    }
    kill(ennemie_pid, SIGUSR2);
    usleep(100);
    for (int i = 0; i < read_val[1] - 48; ++i) {
        kill(ennemie_pid, SIGUSR1);
        usleep(100);
    }
    kill(ennemie_pid, SIGUSR2);
}