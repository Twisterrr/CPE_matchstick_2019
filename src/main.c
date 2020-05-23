/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** Main function of the Matchstick.
*/

#include "matchstick.h"

int main(int ac, char **av)
{
    if (ac != 3)
        return (ERROR);
    char **map = NULL;
    int result = my_getnbr(av[1]) + 2, a = 0;
    map = create_map(av[1], result);
    print_map(map, result);
    a = game(map, result, my_getnbr(av[1]), my_getnbr(av[2]));
    if (a == 84)
        return (ERROR);
    if (a == 512) {
        free_all(map, result);
        return (0);
    }
    if (a == 2)
        return (2);
    if (a == 1)
        return (1);
    free_all(map, result);
    return (0);
}
