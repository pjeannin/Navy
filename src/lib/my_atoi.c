/*
** EPITECH PROJECT, 2019
** to_number
** File description:
** transform a char** to int
*/

int my_atoi(char *nbr)
{
    int res = 0;
    int i = 0;

    while (nbr[i] != '\0') {
        res = res * 10 + nbr[i] - '0';
        ++i;
    }
    return (res);
}