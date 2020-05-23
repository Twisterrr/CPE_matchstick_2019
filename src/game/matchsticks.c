/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** matchsticks
*/

#include "matchstick.h"

int game(char **map, int number, int line, int av2)
{
    int ret = 0;
    index_s *index = malloc(sizeof(*index));
    index->line.linmaxmap = number;
    index->line.linmax = line;
    index->match.av2 = av2;
    index->error.restart = 3;

    ret = start(map, index, number);
    if (ret == 512)
        return (512);
    ret = win_lose(index);
    free (index);
    return (ret);
}

int start(char **map, index_s *index, int number)
{
    int a = 0;
    while (map_check(map, number) > 0) {

        if (index->error.restart == 3) {
            my_putstr("\nYour turn: ");
            index->error.restart = 4;
            }
        if (index->error.restart == 4) {
            a = player_turn(map, index);
            if (a == 512)
                return (512);
            }
            if (a == 1024)
                continue;
        if (map_check(map, number) == 0)
            break;
            start_next(index, map);
        }
    return (0);
}

void start_next(index_s *index, char **map)
{
    int b = 0;
        if (index->error.restart == 7) {
            my_putstr("\nAI's turn...\n");
            index->error.restart = 8;
            }
        if (index->error.restart == 8) {
            b = ia_start(index, map);
        }
}