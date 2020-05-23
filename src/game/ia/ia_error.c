/*
** EPITECH PROJECT, 2020
** ia_error
** File description:
** ia_error
*/

#include "matchstick.h"

int check_line_ia(index_s *index, char **map)
{
    int i = 0;
    int count = 0;

    for (;map[index->line.pline][i];i++)
        if (map[index->line.pline][i] == '|')
            count++;
    if (count == 0)
        return (0);
    if (count > 0) {
        index->count = count;
        return (1);
    }
}