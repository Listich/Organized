/*
** EPITECH PROJECT, 2023
** B-CPE-110-TLS-1-1-organized-serena.kifoula
** File description:
** implementation2.c
*/

#include "libshell/shell.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "include/my.h"


void printf_add(material *new_element)
{
    my_printf("%s n°%d -", new_element->type, new_element->id);
    my_printf(" \"%s\" added.\n", new_element->name);
}

int add(void *data, char **args)
{
    shop *ptr_atelier = (shop *)data;
    material *new_element;
    int current_id;

    for (int i = 0; args[i] != NULL; i += 2) {
        if (add_handling_new(args, i) != 0)
            return 84;
        new_element = malloc(sizeof(material));
        current_id = ptr_atelier->nb_elements;
        ptr_atelier->nb_elements++;
        add_handling(new_element);
        new_element->id = current_id;
        new_element->next = ptr_atelier->first;
        my_strcpy(new_element->type, args[i]);
        my_strcpy(new_element->name, args[i + 1]);
        ptr_atelier->first = new_element;
        printf_add(new_element);
    }
    return 0;
}
