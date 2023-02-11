##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## 
##

SRC		=	src/annexe.c 				\
			src/menu.c 					\
			src/univers.c 				\
			src/main.c 					\

CFLAGS 	=	-W -Wall -Wextra

CSFML	=	-l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

OBJ		=	$(SRC:.c=.o)

NAME	=	jam

all:		$(NAME)

$(NAME):	$(OBJ)
	gcc $(SRC) -o $(NAME)  $(CFLAGS) $(CSFML)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ)

re: 	all fclean

auteur:	echo $(USER) > auteur