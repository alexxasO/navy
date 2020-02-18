/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** Get the flags
*/

#include "../../include/my.h"

int get_flags(const char *format, int pos, int *flag, char *flags2)
{
    char flags[] = "#+ -0";
    int is_flag = 1;

    for (int i = 0; i < 5; i++) {
        if (format[pos] == flags[i] && format[pos] == flags2[i]) {
            flag[0] += my_compute_power_rec(2, i + 1);
            flags2[i] = '\0';
            break;
        } else if (i == 4)
            is_flag = 0;
        if (format[pos] == flags[i])
            break;
    }
    if (is_flag == 1)
        pos = get_flags(format, pos + 1, flag, flags2);
    else
        pos--;
    *flags2 = *flag;
    return pos;
}

int get_width_and_precision(const char *format, int pos, int *w_n_p,
int w_or_p)
{
    int is_nb = 1;

    if (format[pos] >= '0' && format[pos] <= '9') {
        if (w_n_p[w_or_p] != -1) {
            w_n_p[w_or_p] *= 10;
            w_n_p[w_or_p] += format[pos] - 48;
        } else
            w_n_p[w_or_p] = format[pos] - 48;
    } else
        is_nb = 0;
    if (is_nb == 1 && w_or_p != 1)
        pos = get_width_and_precision(format, pos + 1, w_n_p, 0);
    else if (format[pos] == '.' || (w_or_p == 1 && is_nb == 1)) {
        if (w_n_p[1] == -1)
            w_n_p[1] = 0;
        pos = get_width_and_precision(format, pos + 1, w_n_p, 1);
    } else
        pos--;
    return pos;
}

void get_space_n_prec(int *w_n_p, char *type_str, int *space_n_prec,
int *flag_n_type)
{
    int space = w_n_p[0] - my_strlen(type_str);
    int prec = w_n_p[1] - my_strlen(type_str);

    if (space < 0)
        space = 0;
    if (prec < 0)
        prec = 0;
    if (flag_n_type[0] % 32 % 16 % 8 % 4 / 2 == 1 && w_n_p[0] > w_n_p[1]) {
        if (flag_n_type[1] == 4 || flag_n_type[1] == 5) {
            prec++;
            space--;
        } else if (flag_n_type[1] != 3)
            prec++;
    }
    if (flag_n_type[0] % 32 % 16 % 8 / 4 == 1 && w_n_p[0] > w_n_p[1])
        prec++;
    if (flag_n_type[0] % 32 % 16 / 8 == 1 && w_n_p[0] > w_n_p[1])
        prec++;
    space_n_prec[0] = space;
    space_n_prec[1] = prec;
}

int get_size(const char *format, int pos, int *size)
{
    char *sizes = "hlqjzZt";

    for (int i = 0; i < 7; i++)
        if (i < 2 && format[pos + 1] == sizes[i] && format[pos] == sizes[i]) {
            size[0] = 7 + i;
            break;
        } else if (format[pos] == sizes[i]) {
            size[0] = i;
            break;
        }
    if (size[0] == -1)
        return --pos;
    else if (size[0] > 6)
        return ++pos;
    else
        return pos;
}

int get_type(const char *format, int pos, int *type)
{
    char *types = "diuoxXbsScp%";

    for (int i = 0; i < 12; i++)
        if (format[pos] == types[i]) {
            type[1] = i;
            break;
        }
    return pos;
}
