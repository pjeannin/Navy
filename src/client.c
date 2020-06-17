/*
** EPITECH PROJECT, 2020
** client.c
** File description:
** client
*/

#include "navy.h"

int client(navy_t *navy)
{
    connect_client(navy);
    return (game_client(navy));
}