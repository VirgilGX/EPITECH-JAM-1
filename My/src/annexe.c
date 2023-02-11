/*
** EPITECH PROJECT, 2022
** annexe.c
** File description:
** All base function
*/

#include "../includes/jam.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb < 10) {
        my_putchar(nb % 10 + '0');
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    return (nb);
}

int my_putstr(char const *str)
{
    int x = 0;
    while (str[x] != '\0') {
        my_putchar(str[x]);
        x = x + 1;
    }
    return (0);
}

int my_strlen(char const *str)
{
    int x = 0;
    while (str[x] != '\0') {
        x = x + 1;
    }
    return (x);
}
