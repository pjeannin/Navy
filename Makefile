##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

SRC	=	main.c				\
		src/check_map.c		\
		src/init_game.c		\
		src/lib/str.c		\
		src/lib/put_nbr.c	\
		src/load_map.c		\
		src/client.c		\
		src/server.c		\
		src/lib/my_atoi.c	\
		src/action.c		\
		src/connection.c	\
		src/catch_number.c	\
		src/game.c			\
		src/send_coordinates.c	\
		src/check_touch.c		\
		src/display_maps.c		\
		src/lib/get_line.c		\
		src/check_line.c		\
		src/ennemy_round.c		\
		src/player_round.c

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

%.o:	%.c
	@gcc -c -o $@ $< -I$(DEPS)
	@echo "Je transforme $*.c en $*.o"

all:
	$(OBJ)
	@echo "Je lance la compilation de $(NAME) Monsieur"
	@gcc -o $(NAME) $(OBJ) -I${DEPS} $(FLAGS)
	@echo "Compilation termiée Monsiseur"

clean:
	@echo "Je nettoye les .o Monsieur"
	@rm -f $(OBJ)

fclean:
	@echo "Je nettoie tout Monsieur"
	clean
	@rm -f $(NAME)

re:
	fclean all

set:
	reset