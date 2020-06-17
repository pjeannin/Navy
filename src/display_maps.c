/*
** EPITECH PROJECT, 2020
** display_map.c
** File description:
** display_maps
*/

#include "navy.h"

void display_maps(navy_t *navy)
{
    put_str("\nmy positions:\n");
    for (int i = 0; i < 10; ++i) {
        put_str(navy->map[i]);
        put_str("\n");
    }
    put_str("\nennemie positions:\n");
    for (int i = 0; i < 10; ++i) {
        put_str(navy->ennemie_map[i]);
        put_str("\n");
    }
}