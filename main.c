/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "navy.h"

void free_navy(navy_t *navy)
{
    for (int i = 0; i < 10; ++i) {
        free(navy->map[i]);
        free(navy->ennemie_map[i]);
    }
    free(navy);
}

static void init_var(navy_t *navy, int ac, char **av)
{
    struct sigaction sa;
    struct sigaction sa2;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = action;
    sigaction(SIGUSR1, &sa, 0);
    sa.sa_flags = SA_SIGINFO;
    sa2.sa_sigaction = action3;
    sigaction(SIGUSR2, &sa2, 0);
}

int main(int ac, char **av)
{
    navy_t *navy = init_game(ac, av);
    int ret_val;

    if ((int)navy == 84) {
        put_error_str("Bad map file.\n");
        return (84);
    }
    init_var(navy, ac, av);
    if (navy->my_pid == 84)
        return (84);
    if (ac == 3)
        ret_val = client(navy);
    else
        ret_val = server(navy);
    return (ret_val);
}