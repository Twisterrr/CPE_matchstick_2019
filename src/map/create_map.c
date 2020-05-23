/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** Map create of the Matchstick.
*/

#include "matchstick.h"

char *space_create(int xmax, char *map)
{
    int	r = 0;

    while (r != xmax - 1) {
        map[r] = ' ';
        r++;
    }
    map[0] = '*';
    map[r] = '*';
    return (map);
}

char **generation_of_map(int xmax, int ymax, int result)
{
    int	x = 0;
    int	y = 0;
    char **map;
    xmax = xmax - 1;
    map = malloc(sizeof(char *) * (result + 1));

    while (y != ymax) {
        map[y] = malloc(sizeof(char ) * xmax + 1);
        map[y] = space_create(xmax, map[y]);
        if (y < 1 || y == ymax - 1)
        while (x != xmax) {
            map[y][x] = '*';
            x++;
        }
        map[y][xmax] = '\0';
        x = 0;
        y++;
    }
    return (map);
}

void print_map(char **map, int result)
{
    int r = 0;

    for (; r != result; r++) {
        my_putstr(map[r]);
        my_putchar('\n');
    }
}

void free_all(char **tab, int ymax)
{
    int r = 0;

    for (; r != ymax ; r++)
        free(tab[r]);
    free(tab);
}

char **create_map(char *tab, int result)
{
    int	xmax;
    int	ymax;
    char **map;
    int	number;

    number = string_to_number(tab);
    xmax = number_x(number);
    ymax = number_y(number);
    map = generation_of_map(xmax, ymax, result);
    map = stick_create(map, xmax, ymax);
    return (map);
}