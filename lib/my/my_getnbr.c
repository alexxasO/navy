/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Return a number
*/

static int power10(int nb, int pow)
{
    if (nb != -5)
        for (int i = pow; i > 0; i--)
            nb = nb * 10;
    else
        nb = 0;
    return nb;
}

static int get_len(char const *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] >= 48 && str[i] <= 57) || str[i] == 43 && str[i] != 45)
            len++;
        else if (str[i] != 45)
            break;
    return len;
}

static int is_overflow(int result, int number)
{
    if (result <= number)
        return number;
    else
        return 0;
}

int my_getnbr(char const *str)
{
    int number = 0;
    int lenght = get_len(str) - 1;
    int negative = 1;
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] >= 48 && str[i] <= 57 && lenght < 10) || str [i] == 43) {
            number += power10((str[i] - 48), lenght);
            result = is_overflow(result, number);
            lenght--;
        } else if (str[i] == 45)
            negative = -negative;
        else
            break;
    return (result * negative);
}
