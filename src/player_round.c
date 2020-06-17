/*
** EPITECH PROJECT, 2020
** player_round.c
** File description:
** plater_round
*/

#include "navy.h"

void player_round(navy_t *navy)
{
    char *read_val = malloc(sizeof(char) * 100);

    sig = 0;
    put_str("\nattack: ");
    read_val = check_line();
    usleep(1000);
    send_coordinates(navy->ennemie_pid, read_val);
    pause();
    put_str(read_val);
    put_str(": ");
    if (sig == 1) {
        put_str("hit\n");
        navy->ennemie_map[1 + read_val[1] - 48][(read_val[0] - 64) * 2] = 'x';
    } else {
        put_str("missed\n");
        navy->ennemie_map[1 + read_val[1] - 48][(read_val[0] - 64) * 2] = 'o';
    }
    display_maps(navy);
    free(read_val);
}