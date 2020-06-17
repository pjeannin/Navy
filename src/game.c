/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** game
*/

#include "navy.h"

int game_is_not_end(navy_t *navy)
{
    int count_cross = 0;

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 17; ++j)
            if (navy->map[i][j] == 'x')
                ++count_cross;
    if (count_cross == 14)
        return (0);
    count_cross = 0;
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 17; ++j)
            if (navy->ennemie_map[i][j] == 'x')
                ++count_cross;
    if (count_cross == 14)
        return (0);
    return (1);
}

int who_won(navy_t *navy)
{
    int count_cross = 0;

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 17; ++j)
            if (navy->map[i][j] == 'x')
                ++count_cross;
    if (count_cross == 14) {
        put_str("\nEnemy won\n");
        return (1);
    }
    put_str("\nI won\n");
    return (0);
}

int game_server(navy_t *navy)
{
    while (game_is_not_end(navy)) {
        player_round(navy);
        if (game_is_not_end(navy))
            ennemy_round(navy);
    }
    return (who_won(navy));
}

int game_client(navy_t *navy)
{
    while (game_is_not_end(navy)) {
        ennemy_round(navy);
        if (game_is_not_end(navy))
            player_round(navy);
    }
    return (who_won(navy));
}