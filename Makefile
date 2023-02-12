##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile of JAM 1
##

NAME 	=	jam
SRC		=	$(wildcard src/**/*.c src/*.c)
OBJ 	= 	$(SRC:.c=.o)
ARGS 	= 	`arg="$(filter-out $@,$(MAKECMDGOALS))" && echo $${arg:-${1}}`
LFLAGS 	=	-l csfml-system -lcsfml-window -l csfml-graphics -l csfml-audio
CFLAGS 	=	-g3 -Wall -Wextra

$(NAME):
		gcc -o $(NAME) $(SRC) $(LFLAGS) $(CFLAGS)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug:
	make fclean all
	valgrind --log-file="dump" ./$(NAME) $(call ARGS,defaultstring)
	cat -e dump
