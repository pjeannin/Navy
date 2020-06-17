/*
** EPITECH PROJECT, 2020
** check_line.c
** File description:
** check_line
*/

#include "navy.h"

int line_is_not_valid(char *line)
{
    if (str_len(line) != 2)
        return (1);
    if (line[0] < 'A' || line[0] > 'H')
        return (1);
    if (line[1] < '1' || line[1] > '8')
        return (1);
    return (0);
}

char *check_line(void)
{
    char *line = get_line();

    while (line_is_not_valid(line)) {
        put_str("wrong position\nattck: ");
        line = get_line();
    }
    return (line);
}