/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** all_print
*/

#include "matchstick.h"

void resultplay_j(int matches, int lines)
{
    my_putstr("Player removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(lines);
    my_putchar('\n');
}

void	resultplay_e(int matches, int lines)
{
    my_putstr("\nAI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(lines);
    my_putchar('\n');
}

int	result_play(int matches, int lines, int j)
{
    if (j%2 == 0)
        resultplay_j(matches, lines);
    if (j%2 == 1)
        resultplay_e(matches, lines);
    j++;
    return (j);
}