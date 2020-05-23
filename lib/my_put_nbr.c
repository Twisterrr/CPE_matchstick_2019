/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Put
*/

#include "matchstick.h"

int my_put_nbr(int nb)
{
    if (nb < 0 && nb != -2147483648) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb < 10 && nb != -2147483648) {
        my_putchar(nb + 48);
    }
    if (nb == -2147483648) {
        write (1, "-2147483648", 11);
    }
    else if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
}
