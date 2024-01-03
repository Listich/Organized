/*
** EPITECH PROJECT, 2023
** B-CPE-110-TLS-1-1-organized-serena.kifoula
** File description:
** implementation.c
*/

#include "libshell/shell.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "include/my.h"

int print_del(material *current)
{
    my_printf("%s n°%d -", current->type, current->id);
    my_printf(" \"%s\" deleted.\n", current->name);
}

int del_delected(shop *element, int materialid,
    material *current, material *previous)
{
    if (current->id == materialid) {
        if (previous == NULL) {
            element->first = current->next;
        } else {
            previous->next = current->next;
        }
        element->nb_elements--;
        print_del(current);
    }
    return 0;
}

int del(void *data, char **args)
{
    shop *element = (shop *)data;
    int materialid;
    material *current;
    material *previous;

    if (error_handling_del(args)) {
        return 84;
    }
    if (error_handling_del2(element))
        return 84;
    if (error_handling_id(args, element)) {
        return 84;
    }
    for (int i = 0; args[i] != NULL; i++) {
        materialid = my_getnbr(args[i]);
        current = element->first;
        previous = NULL;
        while (current != NULL) {
            del_delected(element, materialid, current, previous);
            previous = current;
            current = current->next;
        }
    }
    return 0;
}

int disp(void *data, char **args)
{
    shop *workshop = (shop *)data;
    material *current = workshop->first;

    if (data == NULL) {
        my_printf(stderr, "Error: Workshop data is NULL \n");
        return 84;
    }
    if (args != NULL) {
        while (current != NULL) {
            my_printf("%s n°%d -", current->type, current->id);
            my_printf(" \"%s\"\n", current->name);
            current = current->next;
        }
        current = workshop->first;
    }
    return 0;
}
