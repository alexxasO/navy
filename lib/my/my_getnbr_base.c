/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Return a number in a given base
*/

#include "../../include/my.h"

static int get_lenght(char const *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 48 && str[i] <= 57) || str[i] == 43)
            len++;
        else if (str[i] != '-')
            break;
    }
    return len;
}

static int turn_in_base_ten(char const *str, char const *base,
int pos, int number)
{
    int result = 0;
    int base_len = my_strlen(base);
    int str_len = my_strlen(str);

    for (int i = 0; i < my_strlen(base); i++)
        if (str[pos] == base[i])
            result = i * my_compute_power_rec(base_len, str_len - pos - 1);
    return result;
}

static int is_in_base(char const *str, char const *base, int pos, int in_base)
{
    if (pos == 0 && (str[pos] == '-' || str[pos] == '+'))
        pos++;
    for (int i = 0; i < my_strlen(base); i++) {
        if (str[pos] == base[i]) {
            in_base++;
            break;
        } else if (i == my_strlen(base) - 1)
            in_base = -100000;
    }
    if (pos != my_strlen(str) - 1)
        in_base = is_in_base(str, base, pos + 1, in_base);
    return in_base;
}

int is_overflow(int result, int number)
{
    if (result <= number)
        return number;
    else
        return 0;
}

int my_getnbr_base(char const *str, char const *base)
{
    int number = 0;
    int lenght = get_lenght(str) - 1;
    int negative = 1;
    int result = 0;

    if (is_in_base(str, base, 0, 0) < 0)
        return -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str [i] == 43 || str[i] != 45) {
            number += turn_in_base_ten(str, base, i, number);
            is_overflow(result, number);
            lenght--;
        } else if (str[i] == 45) {
            negative = -negative;
        } else
            break;
    }
    number *= negative;
    return number;
}
