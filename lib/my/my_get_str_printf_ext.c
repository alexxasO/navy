/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** Put the result of the flags - Extension
*/

#include "../../include/my.h"

static char *get_w_n_p_str_for_spe(int *space_n_prec, int type)
{
    char *str;

    if (type == 10) {
        str = malloc(sizeof(char) * space_n_prec[0] - 1);
        for (int i = 0; i < space_n_prec[0] - 1;i++)
            str[i] = ' ';
        str[space_n_prec[0] - 2] = '\0';
        return str;
    } else if (type == 9) {
        str = malloc(sizeof(char) * space_n_prec[0] + 1);
        for (int i = 0; i < space_n_prec[0] + 1;i++)
            str[i] = ' ';
        str[space_n_prec[0]] = '\0';
        return str;
    }
    return "";
}

static char *get_w_n_p_str_for_int(int *w_n_p, int *space_n_pre,
int flag, int type)
{
    char *str;
    char c = ' ';

    str = get_w_n_p_str_for_spe(space_n_pre, type);
    if (flag / 32 == 1 && w_n_p[1] == -1 && flag % 32 / 16 == 0)
        c = '0';
    if (w_n_p[0] > w_n_p[1] && type != 10 && type != 9) {
        str = malloc(sizeof(char) * space_n_pre[0] + 1);
        for (int i = 0; i < space_n_pre[0] - space_n_pre[1];i++)
            str[i] = c;
        for (int i = space_n_pre[0] - space_n_pre[1]; i < space_n_pre[0];i++)
            str[i] = '0';
        str[space_n_pre[0]] = '\0';
    } else if (type != 10 && type != 9) {
        str = malloc(sizeof(char) * space_n_pre[1] + 1);
        for (int i = 0; i < space_n_pre[1];i++)
            str[i] = '0';
        str[space_n_pre[1]] = '\0';
    }
    return str;
}

char *get_width_str_for_str(int *w_n_p, int *s_n_p,
int *flag_n_typ, char *t_s)
{
    char *str;
    int str_prec = 0;

    if (w_n_p[0] < my_strlen(t_s) && w_n_p[1] < my_strlen(t_s))
        if (flag_n_typ[1] != 7 && flag_n_typ[1] != 8)
            return "";
    if (flag_n_typ[1] < 7 || flag_n_typ[1] == 10 || flag_n_typ[1] == 9)
        str = get_w_n_p_str_for_int(w_n_p, s_n_p, flag_n_typ[0], flag_n_typ[1]);
    else if (flag_n_typ[1] == 7 || flag_n_typ[1] == 8) {
        if (w_n_p[0] > my_strlen(t_s))
            w_n_p[0] = my_strlen(t_s);
        if (w_n_p[1] < my_strlen(t_s) && w_n_p[0] > w_n_p[1] && w_n_p[1] != -1)
            str_prec = w_n_p[0] - w_n_p[1];
        if (w_n_p[1] < my_strlen(t_s) && w_n_p[1] != -1)
            t_s[w_n_p[1]] = '\0';
        str = malloc(sizeof(char) * s_n_p[0] + str_prec + 1);
        for (int i = 0; i < s_n_p[0] + str_prec;i++)
            str[i] = ' ';
        str[s_n_p[0] + str_prec] = '\0';
    }
    return str;
}

char *get_f_str(int flag, int typ, char *typ_str, char *w_n_p_str)
{
    if ((typ <= 1) && typ_str[0] != '-' && flag % 8 / 4 == 1) {
        if (w_n_p_str[0] != '\0')
            w_n_p_str[my_strlen(w_n_p_str) - 1] = '\0';
        return "+";
    }
    if ((typ <= 1) && typ_str[0] != '-' && flag / 8 == 1) {
        if (w_n_p_str[0] != '\0')
            w_n_p_str[my_strlen(w_n_p_str) - 1] = '\0';
        return " ";
    }
    if (flag % 8 % 4 / 2 == 1 && w_n_p_str[0] == ' ' && typ != 10)
        w_n_p_str[my_strlen(w_n_p_str) - 1] = '\0';
    if (flag % 8 % 4 / 2 == 1 && typ == 3)
        return "0";
    if ((flag % 8 % 4 / 2 == 1 && typ == 4) || (typ == 10 && typ_str[0] != '('))
        return "0x";
    if (flag % 8 % 4 / 2 == 1 && typ == 5)
        return "0X";
    return "";
}
