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


Material *merge(Material *left_side, Material *right_side, int sortype,
    bool reverse_sort)
{
    Material *result = NULL;

    if (left_side == NULL) {
        return right_side;
    } else if (right_side == NULL) {
        return left_side;
    }
    switch (sortype) {
    case BY_ID:
        result = mergeby_id(left_side, right_side, reverse_sort);
        break;
    case BY_NAME:
        result = mergeby_name(left_side, right_side, reverse_sort);
        break;
    case BY_TYPE:
        result = mergeby_type(left_side, right_side, reverse_sort);
        break;
    }
    return result;
}

Material *mergeby_id(Material *left, Material *right, bool reversesort)
{
    Material *result = NULL;

    if (reversesort) {
        if (left->id >= right->id) {
            result = left;
            result->next = merge(left->next, right, BY_ID, reversesort);
        } else {
            result = right;
            result->next = merge(left, right->next, BY_ID, reversesort);
        }
    } else {
        if (left->id <= right->id) {
            result = left;
            result->next = merge(left->next, right, BY_ID, reversesort);
        } else {
            result = right;
            result->next = merge(left, right->next, BY_ID, reversesort);
        }
    }
    return result;
}

Material *mergeby_name(Material *left, Material *right, bool reversesort)
{
    Material *result;

    if (reversesort) {
        if (strcmp(left->name, right->name) > 0) {
            result = left;
            result->next = merge(left->next, right, BY_NAME, reversesort);
        } else {
            result = right;
            result->next = merge(left, right->next, BY_NAME, reversesort);
        }
    } else {
        if (strcmp(left->name, right->name) < 0) {
            result = left;
            result->next = merge(left->next, right, BY_NAME, reversesort);
        } else {
            result = right;
            result->next = merge(left, right->next, BY_NAME, reversesort);
        }
    }
    return result;
}

Material *mergeby_type(Material *left, Material *right, bool reversesort)
{
    Material *result;

    if (reversesort) {
        if (strcmp(left->type, right->type) > 0) {
            result = left;
            result->next = merge(left->next, right, BY_TYPE, reversesort);
        } else {
            result = right;
            result->next = merge(left, right->next, BY_TYPE, reversesort);
        }
    } else {
        if (strcmp(left->type, right) < 0) {
            result = left;
            result->next = merge(left, right->next, BY_TYPE, reversesort);
        }
    }
    return result;
}

int splitlist(Material *source, Material **left_side,
    Material **right_side)
{
    Material* ptr_current = source;
    Material* ptr_next = source->next;

    if (source == NULL || source->next == NULL) {
        *left_side = source;
        *right_side = NULL;
        return 0;
    }
    while (ptr_next != NULL) {
        ptr_next = ptr_next->next;
        if (ptr_next != NULL) {
            ptr_current = ptr_current->next;
            ptr_next = ptr_next->next;
        }
    }
    *left_side = source;
    *right_side = ptr_current->next;
    ptr_current->next = NULL;
}

int getsorttype(char *arg)
{
    if (!strcmp(arg, "NAME")) {
        return BY_NAME;
    }
    if (!strcmp(arg, "TYPE")) {
        return BY_TYPE;
        return 0;
    }
    if (!strcmp(arg, "ID")) {
        return BY_ID;
        return 0;
    } else {
        return -1;
    }
    return 0;
}

int sortlist(Material** element, int sortType, bool reverseSort)
{
    Material* left_side;
    Material* right_side;

    if (*element == NULL || (*element)->next == NULL) {
        return 0;
    }
    splitlist(*element, &left_side, &right_side);
    sortlist(&left_side, sortType, reverseSort);
    sortlist(&right_side, sortType, reverseSort);
    *element = merge(left_side, right_side, sortType, reverseSort);
}

int error_handling(char **args, int sort_type)
{
    if (args[0] == NULL) {
        printf("Usage: sort <ID> [-r]\n");
        return 84;
    }
    if (sort_type == -1) {
        printf("Usage: sort <ID>\n");
        return 84;
    }
    return 0;
}

int sort(void *data, char **args)
{
    Shop *shop = (Shop *)data;
    bool reverse_sort = false;
    int sort_type;

    if (shop == NULL || shop->first == NULL) {
        printf("The list is empty, impossible to sort\n");
        return 84;
    }
    sort_type = getsorttype(args[0]);
    error_handling(args, sort_type);
    if (args[1] != NULL && !strcmp(args[1], "-r")) {
        reverse_sort = true;
    }
    sortlist(&(shop->first), sort_type, reverse_sort);
    return 0;
}
