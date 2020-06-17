/*
** EPITECH PROJECT, 2020
** check_map.c
** File description:
** navy
*/

#include "navy.h"

int close_fd(int fd)
{
    close(fd);
    return (1);
}

int close_and_free(int fd, char *buf)
{
    close(fd);
    free(buf);
    return (1);
}

int check_if_positiv(char *buf, int fd)
{
    for (int i = 0; i < 4; ++i) {
        if (buf[i * 8 + 2] != buf[i * 8 + 5]) {
            if (buf[i * 8 + 3] != buf[i * 8 + 6])
                return (close_and_free(fd, buf));
            else if ((int)((int)buf[i * 8 + 5] - (int)buf[i * 8 + 2]) + 1
            != i + 2)
                return (close_and_free(fd, buf));
        } else if (buf[i * 8 + 3] != buf[i * 8 + 6]) {
            if ((int)((int)buf[i * 8 + 6] - (int)buf[i * 8 + 3]) + 1 != i + 2)
                return (close_and_free(fd, buf));
        } else
            return (close_and_free(fd, buf));
    }
    return (0);
}

int map_is_incorrect(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buf = malloc(sizeof(char) * 33);

    if (fd == -1)
        return (1);
    if (buf == NULL)
        return (close_fd(fd));
    if (read(fd, buf, 31) != 31)
        return (1);
    for (int i = 0; i < 4; ++i) {
        if (buf[i * 8] - 48 != i + 2 && buf[i * 8 + 1] != ':') 
            return (close_and_free(fd, buf));
        if ((buf[i * 8 + 2] < 'A' || buf[i * 8 + 2] > 'H') &&
        (buf[i * 8 + 3] < '0' || buf[i * 8 + 3] > '8') && buf[i * 8 + 3] != ':')
            return (close_and_free(fd, buf));
        if ((buf[i * 8 + 5] < buf[i * 8 + 2] || buf[i * 8 + 5] > 'H')
        || (buf[i * 8 + 6] < buf[i * 8 + 3] || buf[i * 8 + 6] > '9'))
            return (close_and_free(fd, buf));
    }
    return (check_if_positiv(buf, fd));
}