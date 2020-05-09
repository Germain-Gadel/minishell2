##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Germain Gadel
##

NAME	=	libmy.a

SRC	=	my_put_nbr.c		\
		my_putchar.c		\
		my_putstr.c		\
		my_strlen.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f ../$(NAME)
		rm -f $(NAME)

re:		fclean all
