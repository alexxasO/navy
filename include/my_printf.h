/*
** EPITECH PROJECT, 2019
** ???
** File description:
** Prototype and struct for my_printf
*/

#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct mod_str
{
    char *typ_str;
    char *w_n_p_str;
    char *fl_str;
} mod_str_t;

typedef struct flags
{
    int *fl_n_typ;
    int *size;
    int *w_n_p;
} flags_t;

int my_printf(const char *format, ...);

int get_flags(const char *format, int pos, int *flag, char *flags2);
int get_width_and_precision(const char *format, int pos, int *w_n_p,
int w_or_p);
void get_space_n_prec(int *w_n_p, char *type_str, int *space_n_prec,
int *flag_n_type);
int get_size(const char *format, int pos, int *size);
int get_type(const char *format, int pos, int *type);

void get_format(va_list ap, int *lenght, flags_t flags);

char *get_typ_str(va_list ap, int type, int size);

char *get_width_str_for_str(int *w_n_p, int *s_n_p,
int *flag_n_type, char *t_s);
char *get_f_str(int flag, int type, char *type_str, char *w_n_p_str);

#endif
