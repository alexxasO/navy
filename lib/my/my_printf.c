/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** Recode of print f
*/

#include "../../include/my.h"

static int check_error(int *fl_n_typ, int size, int *w_n_p)
{
    if (fl_n_typ[1] == -1)
        return -2;
    if (fl_n_typ[1] == 11 && fl_n_typ[0] != 0)
        return -1;
    if (fl_n_typ[1] == 11 && size != -1)
        return -1;
    if (fl_n_typ[1] == 11 && w_n_p[0] != -1)
        return -1;
    if (fl_n_typ[1] == 11 && w_n_p[1] != -1 && w_n_p[1] != 0)
        return -1;
    return 0;
}

static int analyze_format(int i, va_list ap, const char *format,
int *lenght)
{
    int fl_n_typ[] = {0, -1};
    int size[] = {-1};
    int w_n_p[] = {-1, -1};
    char flags2[] = "#+ -0";
    flags_t flags;

    i = get_flags(format, i + 1, fl_n_typ, flags2);
    i = get_width_and_precision(format, i + 1, w_n_p, 0);
    i = get_size(format, i + 1, size);
    i = get_type(format, i + 1, fl_n_typ);
    if (check_error(fl_n_typ, size[0], w_n_p) < 0)
        return check_error(fl_n_typ, size[0], w_n_p);
    flags.fl_n_typ = fl_n_typ;
    flags.size = size;
    flags.w_n_p = w_n_p;
    get_format(ap, lenght, flags);
    return i;
}

static int find_pos_for_mod_typ(const char *format, int pos, int i,
int *lenght)
{
    if (i == -1) {
        my_putchar('%');
        i = pos + 1;
        for (int j = 1; format[j] != '%'; j++)
            i++;
        lenght[0]++;
    } else if (i == -2) {
        my_putchar('%');
        i = pos;
        lenght[0]++;
    }

    return i;
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int lenght[] = {0};
    int i_save = 0;

    va_start(ap, format);
    for (int i = 0; i < my_strlen(format); i++) {
        i_save = i;
        if (format[i] != '%') {
            lenght[0]++;
            my_putchar(format[i]);
        } else
            i = analyze_format(i, ap, format, lenght);
        if (i < 0)
            i = find_pos_for_mod_typ(&format[i_save], i_save, i, lenght);
    }
    va_end(ap);
    return lenght[0];
}
