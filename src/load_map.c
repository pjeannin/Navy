/*
** EPITECH PROJECT, 2020
** load_map.c
** File description:
** load_map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "navy.h"

char dot_or_space(int j)
{
    if (j % 2)
        return (' ');
    return ('.');
}

char **create_empty_map(void)
{
    char **map = malloc(sizeof(char *) * 11);

    for (int i = 0; i < 11; ++i)
        map[i] = malloc(sizeof(char) * 20);
    map[10] = NULL;
    map[0] = " |A B C D E F G H";
    map[1] = "-+---------------";
    for (int i = 2; i < 10; ++i) {
        map[i][0] = (char)(i - 2 + '1');
        map[i][1] = '|';
        for (int j = 2; j < 17; ++j)
            map[i][j] = dot_or_space(j);
        map[i][17] = '\0';
    }
    return (map);
}

char **load_map(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *txtmap = malloc(sizeof(char) * 32);
    char **map = create_empty_map();

    read(fd, txtmap, 31);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < i + 2; ++j)
            if (txtmap[i * 8 + 3] != txtmap[i * 8 + 6])
                map[1 + (int)(txtmap[i * 8 + 3] - 48) + j]
                [((int)(txtmap[i * 8 + 2] - 64) * 2)] = (char)i + 2 + 48;
            else
                map[1 + (int)(txtmap[i * 8 + 3] - 48)]
                [((int)(txtmap[i * 8 + 2] - 64 + j) * 2)] = (char)i + 2 + 48;
    }
    close(fd);
    return (map);
}