##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile that compiles
##

SRC =	$(wildcard *.c) \
		$(wildcard ./lib/my/utils/*.c) \
		$(wildcard ./lib/my/*.c) \
		$(wildcard ./src/*.c)

OBJ = 	$(SRC:.c=.o)

NAME = my_sokoban

CFLAGS = -g3 -I ./lib/my/utils/ -lncurses

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -g3 -W -Werror -Wall -Wextra -o $(NAME) $(CFLAGS) $(OBJ)

lib:
	make -C -lmy

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
