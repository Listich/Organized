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

int printf_arg(char flag, va_list args)
{
    printf_arg_num(flag, args);
    printf_arg_char(flag, args);
    printf_arg_base(flag, args);
    printf_arg_char2(flag, args);
}

void printf_hex(long int b, bool uppercase)
{
    long int decimal_Number = b;
    int i = 1;
    int temp;
    char hexa_Number[100];

    while (decimal_Number != 0) {
        temp = decimal_Number % 16;
        if (temp < 10) {
            temp = temp + 48;
        } else {
            temp = temp + (uppercase ? 55 : 87);
        }
        hexa_Number[i + 1] = temp;
        decimal_Number = decimal_Number / 16;
    }
    for (int j = i -1; j > 0; j--) {
        write(1, &hexa_Number[j], sizeof(char));
    }
}

void printf_octal(int o)
{
    char octalNum[100];
    int i = 0;

    while (o != 0) {
        octalNum[i] = (o % 8)+48;
        o = o / 8;
        i++;
    }
    for (int j = i -1; j >= 0; j--) {
        write(1, &octalNum[j], sizeof(char));
    }
}

void printf_float(double a)
{
    double tmp = a;
    double tmp2;
    double b;

    put_nbr((int)tmp);
    write(1, ".", sizeof(char));
    tmp2 = (int)tmp;
    if (tmp2 > tmp) {
        tmp2--;
    }
    b = (tmp - tmp2) * 1000000;
    put_nbr((int)b);
}

int my_printf(const char *format, ...)
{
    va_list args;
    int pos = 0;
    char c;

    va_start(args, format);
    while (format[pos] != '\0') {
        if (format[pos] == '%') {
            printf_arg(format[pos + 1], args);
            pos += 2;
        } else {
            c = format[pos];
            write(1, &c, sizeof(char));
            pos++;
        }
    }
    va_end(args);
    return 0;
}
