##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## build the lib
##

ECHO =		/bin/echo -e
DEFAULT =	"\033[00m"
GREEN =		"\033[0;32m"
BGREEN =	"\033[1;32m"
TEAL =		"\033[1;36m"
ORANGE =	"\e[1;33m"
RED =		"\033[0;31m"
BRED =		"\033[1;31m"
FLASH =		"\e[5;30m"
BYELLOW =	"\e[1;33m"
BMAGENTA =	"\e[1;35m"

SRC	=	my_compute_power_rec.c \
		my_compute_square_root.c \
		my_find_prime_sup.c \
		my_get_and_put_printf.c \
		my_getnbr_base.c \
		my_getnbr.c \
		my_get_printf.c \
		my_get_str_printf.c \
		my_get_str_printf_ext.c \
		my_isneg.c \
		my_printf.c \
		my_putchar.c \
		my_putnbr_base.c \
		my_putnbr_base_in_str.c \
		my_put_nbr.c \
		my_put_nbr_in_str.c \
		my_putnstr.c \
		my_putstr.c \
		my_putunsnbr_base_in_str.c \
		my_put_uns_nbr_in_str.c \
		my_revstr.c \
		my_shownstr.c \
		my_showstr.c \
		my_showstr_in_str.c \
		my_show_word_array.c \
		my_sort_int_array.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strstr.c \
		my_strupcase.c \
		my_swap.c	\
		get_next_line.c

OBJ	=	$(SRC:.c=.o)

CFLAGS = -g

MY	=	my.h

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ) $(SRC)
	@ar -crs $(NAME) $(OBJ)
	@cp $(NAME) ../

.PHONY: clean re fclean

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

re :	fclean all

.c.o:
		@gcc $(CFLAGS) -c -o $@ $^ && $(ECHO) \
		$(BGREEN)"[OK]"$(BYELLOW) `basename $^` $(DEFAULT) \
		|| $(ECHO) $(BRED)"[ERROR]"$(BYELLOW) $< $(DEFAULT)
