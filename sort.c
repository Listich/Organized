/*
** EPITECH PROJECT, 2023
** B-CPE-110-TLS-1-1-organized-serena.kifoula
** File description:
** sort.c
*/

#include "libshell/shell.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdbool.h>
#include "include/my.h"


int splitlist(material *source, material **leftside,
    material **rightside)
{
    material* ptr_current = source;
    material* ptr_next = source->next;

    if (source == NULL || source->next == NULL) {
        *leftside = source;
        *rightside = NULL;
        return 0;
    }
    while (ptr_next != NULL) {
        ptr_next = ptr_next->next;
        if (ptr_next != NULL) {
            ptr_current = ptr_current->next;
            ptr_next = ptr_next->next;
        }
    }
    *leftside = source;
    *rightside = ptr_current->next;
    ptr_current->next = NULL;
}

int getsorttype(char *arg)
{
    if (!my_strcmp(arg, "NAME")) {
        return BY_NAME;
    }
    if (!my_strcmp(arg, "TYPE")) {
        return BY_TYPE;
        return 0;
    }
    if (!my_strcmp(arg, "ID")) {
        return BY_ID;
        return 0;
    } else {
        return -1;
    }
}

int sortlist(material **element, int sortType, bool reverseSort)
{
    material* leftside;
    material* rightside;

    if (*element == NULL || (*element)->next == NULL) {
        return 0;
    }
    splitlist(*element, &leftside, &rightside);
    sortlist(&leftside, sortType, reverseSort);
    sortlist(&rightside, sortType, reverseSort);
    *element = merge(leftside, rightside, sortType, reverseSort);
}

int error_handling(char **args, int sort_type)
{
    if (args[0] == NULL) {
        my_printf("Usage: sort <ID> [-r]\n");
        return 84;
    }
    if (sort_type == -1) {
        my_printf("Usage: sort <ID>\n");
        return 84;
    }
    return 0;
}

int sort(void *data, char **args)
{
    shop *shop_t = (shop *)data;
    bool reversesort = false;
    int sort_type;

    if (shop_t == NULL || shop_t->first == NULL) {
        my_printf("The list is empty, impossible to sort\n");
        return 84;
    }
    sort_type = getsorttype(args[0]);
    if (error_handling(args, sort_type)) {
        return 84;
    }
    if (args[1] != NULL && !my_strcmp(args[1], "-r")) {
        reversesort = true;
    }
    sortlist(&(shop_t->first), sort_type, reversesort);
    return 0;
}
