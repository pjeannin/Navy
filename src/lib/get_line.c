/*
** EPITECH PROJECT, 2020
** get_line.c
** File description:
** get_line
*/

#include "navy.h"

char *get_line(void)
{
    char *line = malloc(sizeof(char) * 100);
    char *buf = malloc(sizeof(char) * 2);
    int index = 0;

    buf[0] = 'n';
    while (read(0, buf, 1) && *buf != '\n') {
        line[index] = *buf;
        ++index;
    }
    line[index] = '\0';
    free(buf);
    return (line);
}