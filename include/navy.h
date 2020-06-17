/*
** EPITECH PROJECT, 2020
** navy.h
** File description:
** navy
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#ifndef NAVY_H_
#define NAVY_H_

typedef struct s_navy
{
    char **map;
    char **ennemie_map;
    int count_sig;
    pid_t my_pid;
    pid_t ennemie_pid;
} navy_t;

int sig;
int map_is_incorrect(char *filepath);
int str_len(char *str);
void put_error_str(char *str);
navy_t *init_game(int ac, char **av);
char **load_map(char *filepath);
char **create_empty_map(void);
void put_str(char *str);
void put_nbr(int nbr);
int server(navy_t *navy);
int client(navy_t *navy);
int my_atoi(char *nbr);
void action(int signo, siginfo_t *si, void *data);
void action2(int signo, siginfo_t *si, void *data);
void action3(int signo, siginfo_t *si, void *data);
void connect_server(navy_t *navy);
void connect_client(navy_t *navy);
int catch_number(void);
int game_client(navy_t *navy);
int game_server(navy_t *navy);
void send_coordinates(pid_t ennemie_pid, char *read_val);
void check_touch(navy_t *navy, int *coordinates);
void display_maps(navy_t *navy);
char *get_line(void);
char *check_line();
void ennemy_round(navy_t *navy);
void player_round(navy_t *navy);

#endif /* !NAVY_H_ */
