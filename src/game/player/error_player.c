/*
** EPITECH PROJECT, 2020
** error_player_input
** File description:
** error_player_input
*/

#include "matchstick.h"

void verif_match_line(index_s *index, char **map)
{
    int i = 0;
    int count = 0;

    for (; map[index->line.pline][i] != '\0'; i++)
        if (map[index->line.pline][i] == '|')
            count++;
    index->count = count;
}

int arg_verif_player(index_s * index, char **map)
{
    verif_match_line(index, map);
    if (index->match.pmatch > index->match.av2)
        return (5);
    if (index->match.pmatch == 0)
        return (4);
    if (index->match.pmatch > index->count)
        return (3);
    return (0);
}

int alpha(char *word)
{
    int i = 0;
    int count = 0;

    for (; word[i] != '\0';i++)
        if (word[i] >= '0' && word[i] <= '9')
            count++;
    if (count > 0)
        return (666);
    if (count == 0)
        return (0);
    return (0);
}

int line_out(int nb, int pline)
{
    if (nb > pline || nb == 0)
        return (2);
    return (0);
}