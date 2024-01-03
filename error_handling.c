/*
** EPITECH PROJECT, 2023
** B-CPE-110-TLS-1-1-organized-serena.kifoula
** File description:
** error_handling.c
*/

#include "libshell/shell.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "include/my.h"

int add_handling(material *new_element)
{
    if (new_element == NULL) {
        my_printf(stderr, "Error element\n");
        return 84;
    }
    return 0;
}

int add_handling_type(char **args)
{
    for (int i = 0; args[i] != NULL; i++) {
        if(i % 2 == 0 && my_strcmp(args[i], "ACTUATOR") != 0 
        && my_strcmp(args[i], "DEVICE") != 0 
        && my_strcmp(args[i], "PROCESSOR") != 0 
        && my_strcmp(args[i], "SENSOR") != 0 
        && my_strcmp(args[i], "WIRE") != 0) {
            my_printf("invalid type\n");
            return 84;
        }
    }
    return 0;
}

int add_handling_new(char **args, int i)
{
    if (args[i] == NULL || args[i + 1] == NULL) {
        my_printf("Error args\n");
        return 84;
    }
    return 0;
}

int error_handling_id(char **args, shop *shop_t)
{
    for (int i = 0; args[i] != NULL; i++) {
        if (my_getnbr(args[i]) < 0) {
            return 84;
        }
        int valid = 0;
        for (material * a = shop_t->first; a != NULL; a = a->next) {
            if (a->id == my_getnbr(args[i])) {
                valid = 1;
                break;
            }
        }
        if (!valid) {
            return 84;
        }
    }
    return 0;
}
int error_handling_del(char **args)
{
    if (args[0] == NULL) {
        my_printf("Usage: del <ID>\n");
        return 84;
    }
    return 0;
}

int error_handling_del2(shop *element)
{
    if (element->first == NULL) {
        my_printf("The list is empty, no deletions possible.\n");
        return 84;
    }
    return 0;
}
