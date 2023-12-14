/*
** EPITECH PROJECT, 2023
** B-CPE-110-TLS-1-1-organized-serena.kifoula
** File description:
** organized.c
*/

#include "libshell/shell.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

Shop *initialisation()
{
    Shop *shop = (Shop*)malloc(sizeof(*shop));
    if (shop == NULL) {
        return NULL;
    }
    shop->nb_elements = 0;
    shop->first = NULL;
    return shop;
}

int add(void *data, char **args)
{
    Shop *ptr_atelier = (Shop *)data;
    for (int i = 0; args[i] !=  NULL; i+=2) {
        if (args[i] == NULL || args[i + 1] == NULL) {
            printf("Error args\n");
            return 84;
        }
        int current_id = ptr_atelier->nb_elements++;
        Material *new_element = malloc(sizeof(Material));
        if (new_element == NULL) {
            printf("Error element\n");
            return 84;
        }
        new_element->id = current_id;
        new_element->next = ptr_atelier->first;
        strcpy(new_element->type, args[i]);
        strcpy(new_element->name, args[i + 1]);
        ptr_atelier->first = new_element;
        printf("%s n°%d - \"%s\" added.\n", new_element->type,new_element->id, new_element->name);
    }
    return 0;
}

int del(void *data, char **args)
{
    Shop *element = (Shop *)data;
    Material *current = element->first;
    Material *previous = NULL;
    int materialid = atoi(args[0]);

    if (args[0] == NULL) {
        printf("Usage: del <ID>\n");
        return 84;
    }
    if (element->first == NULL)  {
        printf("La liste est vide, aucune suppression possible\n");
        return 0;
    }
    while (current != NULL) {
        if (current->id == materialid) {
            if (previous == NULL) {
                element->first = current->next;
            }else {
                previous->next = current->next;
            }
            element->nb_elements--;
            printf("%s n°%d - \"%s\" deleted.\n", current->type, current->id, current->name);
            return 0;
        }
        previous = current;
        current = current->next;
    }
    return -1;
}

int disp(void *data, char **args)
{
    Shop *workshop = (Shop *)data;
    Material *current = workshop->first;

    if (data == NULL) {
        printf("Error: Workshop data is NULL \n");
        return 84;
    }
    if (args != NULL) {
        while (current != NULL) {
            printf("%s n°%d - \"%s\"\n", current->type, current->id, current->name);
            current = current->next;
        }
        current = workshop->first;
    }
    return 0;
}

int main(int ac, char **av)
{
    Shop *atelier = initialisation();

    if (ac != 1) {
        printf("Too many arguments provided as parameters\n");
        return 84;
    }
    if (atelier == NULL) {
        printf("Workshop memory allocation error.\n");
        return 84;
    }
    workshop_shell(atelier);
    free(atelier);
    return 0;
}
