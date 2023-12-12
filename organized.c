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

int parser(char **args_list, char *commande, int *size_list);


Shop *initialisation()
{
    Shop *shop = (Shop*)malloc(sizeof(*shop));
    if (shop == NULL) {
        return NULL;
    }
    shop->nb_elements = 0;
    shop->first = NULL;
    return shop ;
}

int add(void *data, char **args)
{
    Shop *ptr_atelier = (Shop *)data;
    for (int i = 0; args[i] !=  NULL; i+=2) {
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
    (void)data;
    (void)args;
    printf("tu a bien del\n");
}

int sort(void *data, char **args)
{
    (void)data;
    (void)args;
    printf("tu à bien sort\n");
}

int disp(void *data, char **args)
{
    //il ne fonctionne pas
    if (data == NULL) {
        printf("Error: Workshop data is NULL \n");
        return 84;
    }
    Shop *workshop = (Shop *)data;
    Material *current = workshop->first;
    if (args != NULL)
    {
        for (int i = 0; args[i] != NULL; i++)
        {
            while (current != NULL)
            {
                if (strcmp(current->type, args[i]) == 0) {
                    printf("%s n°%d - \"%s\"\n", current->type, current->id, current->name);
                }
                current = current->next;
            }
            current = workshop->first;
        }
    }
    return 0;
}

int parser(char **args_list, char *commande, int *size_list)
{
    char *buffer = (char *)malloc(27*sizeof(char));
    int j = 0;
    int index = 0;
    *size_list = 0;

    for (int i = 0; commande[i] != '\n'; i++) {
        if (commande[i] != ' ' && commande[i] != ',') {
            buffer[j] = commande[i];
            j++;
        } else {
            if (index > 0 ) {
            buffer[j] = '\0';
            args_list[index] = (char *)malloc((j)* sizeof(char));
            strcpy(args_list[index], buffer);
            size_list++;
            }
            j = 0;
        }
    }
    free(buffer);
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