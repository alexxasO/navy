/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** Analyse the flag and put the result
*/

#include "../../include/my.h"

static void put_format_with_minus_and_free(int *fl_n_typ, int *s_n_p,
mod_str_t mod_str)
{
    if (fl_n_typ[0] % 32 / 16 == 1 && s_n_p[0] - s_n_p[1] > 0) {
        my_putstr(mod_str.fl_str);
        if (fl_n_typ[1] != 7 && fl_n_typ[1] != 8 && fl_n_typ[1] != 10)
            my_putstr(&mod_str.w_n_p_str[s_n_p[0] - s_n_p[1]]);
        my_putstr(mod_str.typ_str);
        if (fl_n_typ[1] == 7 || fl_n_typ[1] == 8)
            my_putstr(&mod_str.w_n_p_str[s_n_p[0] - s_n_p[1]]);
    }
    if (fl_n_typ[0] % 32 / 16 == 1 && s_n_p[0] - s_n_p[1] >= 0)
        my_putnstr(mod_str.w_n_p_str, s_n_p[0] - s_n_p[1]);
    if (fl_n_typ[1] == 10 && mod_str.typ_str[0] == '(')
        return;
    if (fl_n_typ[1] != 11)
        free(mod_str.typ_str);
    if (mod_str.w_n_p_str[0] != '\0' || fl_n_typ[1] == 7 || fl_n_typ[1] == 8)
        free(mod_str.w_n_p_str);
}

static void put_format_without_minus(int *fl_n_typ, int *s_n_p,
mod_str_t mod_str)
{
    int j = 0;

    if (fl_n_typ[0] % 32 / 16 != 1 || s_n_p[0] - s_n_p[1] <= 0) {
        if (fl_n_typ[1] < 7 && mod_str.typ_str[0] == '-')
            my_putchar('-');
        for (j = 0; mod_str.w_n_p_str[j] == ' '; j++)
            my_putchar(mod_str.w_n_p_str[j]);
        my_putstr(mod_str.fl_str);
        if (fl_n_typ[1] < 2 && s_n_p[1] == s_n_p[0])
            if (mod_str.w_n_p_str[0] == '0' && fl_n_typ[0] % 32 % 16 / 8 == 1)
                my_putchar(mod_str.w_n_p_str[0]);
        for (j = j; mod_str.w_n_p_str[j] == '0'; j++)
            my_putchar(mod_str.w_n_p_str[j]);
        if (fl_n_typ[1] < 7 && mod_str.typ_str[0] == '-')
            my_putstr(&mod_str.typ_str[1]);
        else
            my_putstr(mod_str.typ_str);
    }
    put_format_with_minus_and_free(fl_n_typ, s_n_p, mod_str);
}

static int get_lenght(mod_str_t mod_str)
{
    int lenght = 0;

    lenght += my_strlen(mod_str.typ_str);
    lenght += my_strlen(mod_str.fl_str);
    lenght += my_strlen(mod_str.w_n_p_str);
    return lenght;
}

void get_format(va_list ap, int *lenght, flags_t flags)
{
    int s_n_p[] = {-1, -1};
    mod_str_t mod_str;
    char *t_str;
    char *w_n_p_str;
    int *fl_n_typ = flags.fl_n_typ;
    int *size = flags.size;
    int *w_n_p = flags.w_n_p;

    t_str = get_typ_str(ap, fl_n_typ[1], size[0]);
    get_space_n_prec(w_n_p, t_str, s_n_p, fl_n_typ);
    w_n_p_str = get_width_str_for_str(w_n_p, s_n_p, fl_n_typ, t_str);
    mod_str.fl_str = get_f_str(fl_n_typ[0] % 16, fl_n_typ[1], t_str, w_n_p_str);
    mod_str.typ_str = t_str;
    mod_str.w_n_p_str = w_n_p_str;
    lenght[0] += get_lenght(mod_str);
    put_format_without_minus(fl_n_typ, s_n_p, mod_str);
}
