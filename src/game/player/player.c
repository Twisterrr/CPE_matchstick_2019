/*
** EPITECH PROJECT, 2020
** player
** File description:
** player
*/

#include "matchstick.h"

int player_match_check(index_s *index, char *word, char **map)
{
    if (alpha(word) == 0) {
        my_putstr("Error: invalid input (positive number expected)");
        free (word);
        return (84);
        }
    index->match.pmatch = my_getnbr(word);
    if (arg_verif_player(index, map) == 3) {
        my_putstr("Error: not enough matches on this line");
        return (84);
        }
    if (arg_verif_player(index, map) == 5) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(index->match.av2);
        my_putstr(" matches per turn");
        return (84);
        }
    if (arg_verif_player(index, map) == 4) {
        my_putstr("Error: you have to remove at least one match");
        return (84);
        }
}

int player_match(index_s *index, char **map)
{
    size_t size = 10;
    char *word = NULL;

    my_putstr("Matches: ");
    getline(&word, &size, stdin);
    if (*word == '\0') {
        free (word);
        return (512);
    }
    index->error.error = player_match_check(index, word, map);
    if (index->error.error == 84)
        return (1024);
    index->match.pmatch = my_getnbr(word);
    free (word);
    return (0);
}

int player_line_check(index_s *index, char *word)
{
    if (alpha(word) == 0) {
        my_putstr("Error: invalid input (positive number expected)");
        free (word);
        return (84);
    }
    if (line_out(my_getnbr(word), index->line.linmax) == 2) {
        my_putstr ("Error: this line is out of range");
        return (84);
    }
}

int player_line(index_s *index)
{
    size_t size = 10;
    char *word = NULL;

    my_putstr("\nLine: ");
    getline(&word, &size, stdin);
    if (*word == '\0') {
        free (word);
        return (512);
    }
    index->error.error = player_line_check(index, word);
    if (index->error.error == 84)
        return (1024);
    index->line.pline = my_getnbr(word);
    free(word);
    return (0);
}

int player_turn(char **map, index_s *index)
{
    int a = player_line(index);
    int b = 0;

    if (a == 512)
        return (512);
    if (a == 1024)
        return (1024);

    b = player_match(index, map);
    if (b == 512)
        return (512);
    if (b == 1024)
        return (1024);
    resultplay_j(index->match.pmatch, index->line.pline);
    removed_stick(map, index->line.pline, index->match.pmatch);
    print_map(map, index->line.linmaxmap);
    index->error.restart = 7;
    return (0);
}