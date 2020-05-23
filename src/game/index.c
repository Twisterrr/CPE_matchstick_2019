/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** index
*/

#include "matchstick.h"

int my_atoi(char *str)
{
    int val = 0;
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            val *= 10;
            val += *str - '0';
        }else
            return (val);
            str++;
        }
    return (val);
}

int	map_check(char **map, int linemax)
{
    int	i = 0;
    int	j = 0;
    int	nb = 0;

    while (i < linemax) {
        while (map[i][j] != '\0') {
            if (map[i][j] == '|')
                nb++;
            j++;
        }
        j = 0;
        i++;
    }
    return (nb);
}

int removed_stick(char **map, int pline, int match)
{
    int r = 0;

    for (; map[pline][r] != '\0'; r++);
    for (; r > 0; r--)
        if (map[pline][r] == '|' && match > 0) {
            map[pline][r] = ' ';
            match--;
        }
}

int	win_lose(index_s *index)
{
    if (index->error.restart == 7) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    if (index->error.restart == 3) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
}