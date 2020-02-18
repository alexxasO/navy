/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** Put the result of the flags
*/

#include "../../include/my.h"

static unsigned long long int apply_size_for_uns(va_list ap, int size)
{
    unsigned long long int number = 0;

    if (size == 0 || size == 7)
        number = va_arg(ap, int);
    if (size == 1 || (size > 2 && size < 7))
        number = va_arg(ap, unsigned long int);
    if (size == 2 || size == 8)
        number = va_arg(ap, unsigned long long int);
    else if (size == -1)
        number = va_arg(ap, unsigned int);
    return number;
}

static long long int apply_size_for_sig(va_list ap, int size)
{
    long long int number = 0;

    if (size == 0 || size == 7)
        number = va_arg(ap, int);
    if (size == 1 || (size > 2 && size < 7))
        number = va_arg(ap, long int);
    if (size == 2 || size == 8)
        number = va_arg(ap, long long int);
    else if (size == -1)
        number = va_arg(ap, int);
    return number;
}

static char *get_type_str_for_str(va_list ap, int type)
{
    char *str;
    char *str2;

    if (type == 7 || type == 8) {
        if (type == 7)
            str2 = va_arg(ap, char *);
        else
            str2 = my_showstr_in_str(va_arg(ap, char *));
        str = malloc(sizeof(char) * my_strlen(str2) + 1);
        str = my_strcpy(str, str2);
        if (type == 8)
            free(str2);
    } else if (type == 10) {
        str = my_putnbr_base_in_str(va_arg(ap, size_t), "0123456789abcdef");
        if (str[0] == '0' && str[1] == '\0') {
            free(str);
            str = "(nil)";
        }
    }
    return str;
}

static char *get_type_str_ext(va_list ap, int type, int size)
{
    char *str;
    char *base;

    if (type == 5) {
        base = "0123456789ABCDEF";
        str = my_putunsnbr_base_in_str(apply_size_for_uns(ap, size), base);
    }
    if (type == 6)
        str = my_putunsnbr_base_in_str(apply_size_for_uns(ap, size), "01");
    if (type == 9) {
        str = malloc(sizeof(char) * 2);
        str[0] = va_arg(ap, int);
        str[1] = '\0';
    } else if (type == 7 || type == 8 || type == 10)
        str = get_type_str_for_str(ap, type);
    if (type == 11)
        str = "%";
    return str;
}

char *get_typ_str(va_list ap, int type, int size)
{
    char *str;
    char *base;

    if (type == 0 || type == 1)
        str = my_put_nbr_in_str(apply_size_for_sig(ap, size));
    if (type == 2)
        str = my_put_uns_nbr_in_str(apply_size_for_uns(ap, size));
    if (type == 3) {
        base = "01234567";
        str = my_putunsnbr_base_in_str(apply_size_for_uns(ap, size), base);
    } else if (type == 4) {
        base = "0123456789abcdef";
        str = my_putunsnbr_base_in_str(apply_size_for_uns(ap, size), base);
    }
    if (type > 4)
        str = get_type_str_ext(ap, type, size);
    return str;
}
