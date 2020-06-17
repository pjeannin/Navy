/*
** EPITECH PROJECT, 2020
** ennemy_round.c
** File description:
** ennemy_round
*/

#include "navy.h"

void ennemy_round(navy_t *navy)
{
    int *coordinates = malloc(sizeof(int) * 2);

    put_str("\nwaiting for enemy's attack...\n");
    coordinates[0] = catch_number();
    coordinates[1] = catch_number();
    check_touch(navy, coordinates);
    display_maps(navy);
    free(coordinates);
}