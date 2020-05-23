##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile of the Matchstick.
##

NAME	=	matchstick

CC		=	gcc -o

SRC	=	src/main.c 					\
		src/map/create_map.c 		\
		src/map/utils_map.c 		\
		src/game/all_print.c 		\
		src/game/index.c			\
		src/game/matchsticks.c 		\
		src/game/player/player.c	\
		src/game/player/error_player.c	\
		src/game/ia/ia.c	\
		src/game/ia/ia_error.c	\
		lib/my_getnbr.c 			\
		lib/my_putstr.c 			\
		lib/my_put_nbr.c 			\
		lib/my_putchar.c 			\

OBJ    =    $(SRC:.c=.o)

CFLAGS    +=    -Wall -Wextra -I./include -g3

all:    $(NAME)

$(NAME):    $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
