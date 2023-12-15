/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_printf.c
*/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdarg.h>
#include "../include/my.h"

void printchar(char c)
{
    write(1, &c, 1);
}

int put_nbr(int nb)
{
    if (nb > 9)
        put_nbr(nb / 10);
    else if (nb < 0) {
        nb = nb * - 1;
        write(1, "-", 1);
        put_nbr(nb / 10);
    }
    printchar(nb % 10 + '0');
}

int put_unbr(unsigned int nb)
{
    if (nb > 9)
        put_unbr(nb / 10);
    else if (nb < 0) {
        nb = nb * -1;
        write(1, "-", 1);
        put_unbr(nb / 10);
    }
    printchar(nb % 10 + '0');
}
