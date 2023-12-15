/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** my.h
*/

#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <stddef.h>
    #include <sys/wait.h>
    #include <errno.h>
    #include <string.h>
int printf_arg(char flag, va_list args);
void printf_hex(long int b, bool uppercase);
void printf_octal(int o);
void printf_float(double a);
int my_printf(const char *format, ...);
void printchar(char c);
int put_nbr(int nb);
int put_unbr(unsigned int nb);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int printf_arg_num(char flag, va_list args);
int printf_arg_char2(char flag, va_list args);
int printf_arg_char(char flag, va_list args);
int printf_arg_base(char flag, va_list args);
int my_getnbr(char const *str);
#endif /*MY_H_*/
