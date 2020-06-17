/*
** EPITECH PROJECT, 2020
**  server.c
** File description:
** server
*/

#include "navy.h"

int server(navy_t *navy)
{
    connect_server(navy);
    return (game_server(navy));
}