/*
** EPITECH PROJECT, 2019
** ???
** File description:
** Prototype of lib functions
*/

#ifndef MY_H
#define MY_H

#include "my_printf.h"

void my_putchar(char c);
int my_putstr(char const *str);
int my_putnstr(char const *str, int n);
int my_put_nbr(long long int nb);
int my_putnbr_base(long long int nbr, char const *base);
void my_put_double(double nb, int pow_precision);
int my_showstr(char const *str);
int my_shownstr(char const *str, int n);
int my_show_word_array(char * const *tab);

int my_isneg(int nb);
int my_is_prime(int nb);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);

char *my_showstr_in_str(char const *str);
char *my_put_nbr_in_str(long long int nb);
char *my_put_uns_nbr_in_str(unsigned long long int nb);
char *my_putnbr_base_in_str(long long int nbr, char const *base);
char *my_putunsnbr_base_in_str(unsigned long long int nbr, char const *base);

char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);

int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);

int my_getnbr(char const *str);
int my_getnbr_base(char const *str, char const *base);

int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);

void my_swap(int *a, int *b);

int my_strlen(char const *str);

void my_sort_int_array(int *tab, int size);

int my_find_prime_sup(int nb);

#endif
