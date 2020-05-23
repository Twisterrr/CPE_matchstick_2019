/*
** EPITECH PROJECT, 2019
** CPE_matchstick
** File description:
** Header of the Matchstick.
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define ERROR 84

typedef struct error_t
{
    int error;
    int restart;
}error_s;

typedef struct line_t
{
    int linmaxmap;
    int linmax;
    int pline;
}line_s;

typedef struct match_t
{
    int matchmax;
    int pmatch;
    int av2;
}match_s;

typedef struct index_t
{
    struct error_t error;
    struct line_t line;
    struct match_t match;
    int count;
}index_s;

//Main
int main(int ac, char **av);

//      { Game }
int	map_check(char **map, int linemax);
int	win_lose(index_s *index);
int game(char **map, int number, int line, int av2);
int start(char **map, index_s *index, int number);
int removed_stick(char **map, int pline, int match);
void start_next(index_s *index, char **map);
void resultplay_j(int matches, int lines);
// player
int player_turn(char **map, index_s *index);
int player_line(index_s *index);
int alpha(char *word);
int line_out(int nb, int pline);
int player_match(index_s *index, char **map);
int player_match_check(index_s *index, char *word, char **map);
void verif_match_line(index_s *index, char **map);
int arg_verif_player(index_s *index, char **map);
// ia
int ia_start(index_s *index, char **map);
int check_line_ia(index_s *index, char **map);

//Create Map
char **create_map(char *tab, int result);
void print_map(char **map, int result);
char **generation_of_map(int xmax, int ymax, int result);
char *space_create(int xmax, char *map);
char **stick_create(char **map, int xmax, int ymax);
int	number_x(int number);
int	number_y(int number);
int	string_to_number(char *tab);
int	count(char *tab);
void free_all(char **tab, int ymax);

//Lib
int my_getnbr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);

#endif /* MATCHSTICK_H_ */