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

void printf_arg_other(char flag, va_list args)
{
    switch (flag) {
    case '\n':
        printchar("\n");
        break;
    case '\r':
        printchar("\r");
    case '\t':
        printchar("\t");
        break;
    case '\\':
        printchar("\\");
        break;
    case '\b':
        printchar("\b");
    default:
        break;
    }
}
