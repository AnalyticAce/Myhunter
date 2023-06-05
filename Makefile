##
## EPITECH PROJECT, 2022
## my_hunter
## File description:
## my hunter makefile
##

SRC	=	game1.c    \
		game2.c    \
		my_putstr.c    \
		my_putchar.c    \

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

all:	$(NAME)

$(NAME):
	gcc $(SRC) -lcsfml-graphics -lcsfml-window -lcsfml-system -o $(NAME) -g3
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
