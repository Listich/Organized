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


int printf_arg_num(char flag, va_list args)
{
    int d;
    double f;
    int u;

    switch (flag) {
    case 'd':
    case 'i':
        d = va_arg(args, const int);
        put_nbr(d);
        break;
    case 'f':
        f = va_arg(args, const double);
        printf_float(f);
        break;
    case 'u':
        u = va_arg(args, int);
        put_unbr((unsigned)u);
        break;
    }
}

int printf_arg_char2(char flag, va_list args)
{
    long int p;

    switch (flag) {
    case '%':
        write(1, "%%", sizeof(char));
        break;
    case 'p':
        p = va_arg(args, long int);
        write(1, "0x", sizeof(char) * 2);
        printf_hex(p, false);
        break;
    }
}

int printf_arg_char(char flag, va_list args)
{
    char *result;
    char c;

    switch (flag) {
    case 's':
        result = va_arg(args, const char *);
        write(1, result, my_strlen(result));
        break;
    case 'c':
        c = va_arg(args, const int);
        write(1, &c, sizeof(char));
        break;
    }
}

int printf_arg_base(char flag, va_list args)
{
    int x;
    int xu;
    int o;

    switch (flag) {
    case 'x':
        x = va_arg(args, int);
        printf_hex(x, false);
        break;
    case 'X':
        xu = va_arg(args, int);
        printf_hex(xu, true);
        break;
    case 'o':
        o = va_arg(args, int);
        printf_octal(o);
        break;
    default:
        break;
    }
}
