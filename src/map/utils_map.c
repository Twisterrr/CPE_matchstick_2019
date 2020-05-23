/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** Utils necessary for create the map of the Matchstick.
*/

#include "matchstick.h"

int	count(char *tab)
{
    int	r = 0;

    while (tab[r] != '\0')
        r++;
    return (r);
}

int	string_to_number(char *tab)
{
    int	size = count(tab);
    int	r = 0;
    int	number = 0;
    int	multi = 1;

    while (size != 1) {
        multi = multi * 10;
        size--;
    }
    while (tab[r] != '\0') {
        number = number + ((tab[r] - 48) * multi);
        multi = multi /10;
        r++;
    }
    return (number);
}

int	number_y(int number)
{
    int	result;

    result = number + 2;
    return (result);
}

int	number_x(int number)
{
    int	result = 1;
    int	r = 0;

    while (r != number) {
        result = result + 2;
        r++;
    }
    result = result + 1;
    return (result);
}

char **stick_create(char **map, int xmax, int ymax)
{
    int	x = (xmax/2) - 1;
    int	y = 1;
    int	count = 1;
    int	i = 0;
    xmax = xmax - 1;

    while (y != ymax - 1) {
        while (count != i) {
            map[y][x + i] = '|';
            map[y][x - i] = '|';
            i++;
        }
        i = 0;
        count++;
        y++;
    }
    return (map);
}