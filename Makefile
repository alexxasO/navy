##
## EPITECH PROJECT, 2019
## PROJECT NAME
## File description:
## Makefile for PROJECT NAME
##

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

TEST	=	\

NAME	=	navy

CFLAGS	+= -W -Wall -Wextra -Iinclude -Llib/my -lmy -g

CRITERION += --coverage -lcriterion

all :		$(OBJ)
	make -C lib/my all
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

tests_run :
	make -C lib/my all
	gcc -o unit_tests $(TEST) $(CFLAGS) $(CRITERION)
	./unit_tests

clean :
	rm -f $(OBJ)

fclean :        clean
	rm -f $(NAME)
	make -C lib/my clean

re :            fclean all
