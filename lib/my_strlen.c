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

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return (count);
}
