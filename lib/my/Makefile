##
## EPITECH PROJECT, 2019
## ???
## File description:
## Makefile for lib
##

SRC =		my_putchar.c			\
		my_isneg.c			\
		my_put_nbr.c			\
		my_swap.c			\
		my_putstr.c			\
		my_strlen.c			\
		my_getnbr.c			\
		my_sort_int_array.c		\
		my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_find_prime_sup.c		\
		my_strcpy.c			\
		my_strncpy.c			\
		my_revstr.c			\
		my_strstr.c			\
		my_strcmp.c			\
		my_strncmp.c			\
		my_strupcase.c			\
		my_strlowcase.c			\
		my_strcapitalize.c		\
		my_str_isalpha.c		\
		my_str_isnum.c			\
		my_str_islower.c		\
		my_str_isupper.c		\
		my_str_isprintable.c		\
		my_strcat.c			\
		my_strncat.c			\
		my_show_word_array.c		\
		my_strdup.c			\
		my_putnbr_base.c		\
		my_getnbr_base.c		\
		my_put_nbr_in_str.c		\
		my_putnbr_base_in_str.c		\
		my_putnstr.c			\
		my_showstr.c			\
		my_shownstr.c			\
		my_showstr_in_str.c		\
		my_putunsnbr_base_in_str.c	\
		my_put_uns_nbr_in_str.c		\
		my_printf.c			\
		my_get_printf.c                 \
		my_get_and_put_printf.c		\
		my_get_str_printf.c		\
		my_get_str_printf_ext.c

OBJ =		$(SRC:.c=.o)

all :		create_library

create_library : $(0BJ)
	gcc -c $(SRC)
	ar rc libmy.a $(OBJ)

clean :
	rm libmy.a
	rm $(OBJ)
