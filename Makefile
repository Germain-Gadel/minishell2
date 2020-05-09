##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Germain Gadel
##

SRC	=	src/main.c	\
		src/my_str_to_word_array.c	\
		src/my_strtwa_2.c	\
		src/my_strcat.c	\
		src/my_revstr.c	\
		src/my_strcmp.c	\
		src/free_double.c	\
		src/my_getnbr.c	\
		src/my_fix_str.c	\
		src/cd_command.c	\
		src/change_envp.c	\
		src/check_env_command.c	\
		src/change_prompt.c	\
		src/exit_pwd_command.c	\
		src/find_in_envp.c	\
		src/launch_command.c	\
		src/len_array.c	\

LIB_DIR	=	./lib/my

INC_DIR	=	./include

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	+=	-Wall -Wextra -L$(LIB_DIR) -lmy -I$(INC_DIR)

CFLAGS_DEBUG	+=	-Wall -Wextra -L$(LIB_DIR) -lmy -I$(INC_DIR) -g

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C $(LIB_DIR)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

debug:		$(OBJ)
	make -C $(LIB_DIR)
	gcc -o $(NAME) $(OBJ) $(CFLAGS_DEBUG)

clean:
		make clean -C $(LIB_DIR)
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)
		rm -f $(OBJ)
		make fclean -C $(LIB_DIR)

re:	fclean all