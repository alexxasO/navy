/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Sort an integer array
*/

#include "../../include/my.h"

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int k = 0;

    for (int j = 0; i < size && j < size; j++)
        if (array[i] > array[j]) {
            k = array[i];
            array[i] = array[j];
            array[j] = k;
            j = i;
        } else if (j == size) {
            i++;
            j = i;
        }
}
