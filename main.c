/*
** EPITECH PROJECT, 2023
** B-CPE-110-TLS-1-1-organized-serena.kifoula
** File description:
** main.c
*/

#include "libshell/shell.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "include/my.h"

shop *initialisation(void)
{
    shop *shop_t = (shop*)malloc(sizeof(*shop_t));

    if (shop_t == NULL) {
        return NULL;
    }
    shop_t->nb_elements = 0;
    shop_t->first = NULL;
    return shop_t;
}

int main(int ac, char **av)
{
    shop *atelier = initialisation();

    if (ac != 1) {
        my_printf("Too many arguments provided as parameters\n");
        return 84;
    }
    if (atelier == NULL) {
        my_printf("Workshop memory allocation error.\n");
        return 84;
    }
    workshop_shell(atelier);
    free(atelier);
    return 0;
}
