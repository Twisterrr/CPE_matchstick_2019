/*
** EPITECH PROJECT, 2020
** ia
** File description:
** ia
*/

#include "matchstick.h"

int ia_start(index_s *index, char **map)
{
    index->line.pline = random() % index->line.linmax + 1;
    if (check_line_ia(index, map) == 0)
        return (2048);
    index->match.pmatch = random () % index->count;
    while (index->match.pmatch > index->match.av2 || index->match.pmatch == 0) {
        if (index->count != 1)
            index->match.pmatch = random () % index->count;
        else
            index->match.pmatch = 1;
    }

    my_putstr("AI removed ");
    my_put_nbr(index->match.pmatch);
    my_putstr(" match(es) from line ");
    my_put_nbr(index->line.pline);
    my_putchar(10);
    removed_stick(map, index->line.pline, index->match.pmatch);
    print_map(map, index->line.linmaxmap);
    index->error.restart = 3;
}