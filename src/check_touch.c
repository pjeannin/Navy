/*
** EPITECH PROJECT, 2020
** check_touch.c
** File description:
** check_touch
*/

#include "navy.h"

void check_touch(navy_t *navy, int *coordinates)
{
    char *print_val = malloc(sizeof(char) * 3);

    print_val[0] = coordinates[0] + 64;
    print_val[1] = coordinates[1] + 48;
    print_val[2] = '\0';
    put_str(print_val);
    if (navy->map[1 + coordinates[1]][coordinates[0] * 2] >= '2'
    && navy->map[1 + coordinates[1]][coordinates[0] * 2] <= '5') {
        usleep(100);
        kill(navy->ennemie_pid, SIGUSR1);
        navy->map[1 + coordinates[1]][coordinates[0] * 2] = 'x';
        put_str(": hit\n");
    } else {
        usleep(100);
        kill(navy->ennemie_pid, SIGUSR2);
        navy->map[1 + coordinates[1]][coordinates[0] * 2] = 'o';
        put_str(": missed\n");;
    }
}