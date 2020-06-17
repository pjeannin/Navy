/*
** EPITECH PROJECT, 2020
** init_game.c
** File description:
** init_game
*/

#include "navy.h"

void display_usage(void)
{
    put_str("USAGE\n     ./navy [first_player_pid] navy_positions\n");
    put_str("DESCRIPTION\n     first_player_pid:  ");
    put_str("only for the 2nd player.  ");
    put_str("pid of the first player.\n     ");
    put_str("navy_positions:  file representing ");
    put_str("the positions of the ships.\n");
}

navy_t *init_game(int ac, char **av)
{
    navy_t *navy = malloc(sizeof(navy_t));

    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
            display_usage();
        } else if (map_is_incorrect(av[1]))
            return ((navy_t *)84);
    } else if (ac == 3) {
        if (map_is_incorrect(av[2]))
            return ((navy_t *)84);
        navy->ennemie_pid = my_atoi(av[1]);
    } else
        return ((navy_t *)84);
    navy->map = load_map(av[ac - 1]);
    navy->my_pid = getpid();
    navy->ennemie_map = create_empty_map();
    put_str("my_pid: ");
    put_nbr(navy->my_pid);
    put_str("\n");
    return (navy);
}