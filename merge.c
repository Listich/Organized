/*
** EPITECH PROJECT, 2023
** B-CPE-110-TLS-1-1-organized-serena.kifoula
** File description:
** merge_sort.c
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

int get_sortype_index(int *sortype, int current_type)
{
    for (int i = 0; i < 3; i++) {
        if (sortype[i] == current_type && i < 2) {
            return i + 1;
        }
    }
    return -1;
}

material *merge(material *leftside, material *rightside, Sort_t *liste, int *index)
{
    material *result = NULL;

    if (leftside == NULL) {
        return rightside;
    } else if (rightside == NULL) {
        return leftside;
    }
    switch (sortype[0]) {
    case BY_ID:
        result = mergeby_id(leftside, rightside,liste, index);
        break;
    case BY_NAME:
        result = mergeby_name(leftside, rightside, liste, index);
        break;
    case BY_TYPE:
        result = mergeby_type(leftside, rightside, liste, index);
        break;
    }
    return result;
}

material *mergeby_id(material *left, material *right, Sort_t *liste, index)
{
    material *result = NULL;

    if (liste[index].reverse) {
        if (left->id >= right->id) {
            result = left;
            if (left->id == right->id) {
                int index = get_sortype_index(sortype, BY_ID);
            if (index != -1) {
                result->next = merge(left->next, right, sortype[index], reversesort);
            } else {
                result->next = merge(left->next, right, BY_ID, reversesort);
            }
        } else {
            result = right;
            result->next = merge(left, right->next, BY_ID, reversesort);
        }
    } else {
        if (left->id <= right->id) {
            result = left;
            if (left->id == right->id) {
                int index = get_sortype_index(sortype, BY_ID);
            if (index != -1) {
                result->next = merge(left->next, right, sortype[index], reversesort);
            } else {
                result->next = merge(left->next, right, BY_ID, reversesort);
            }
            result->next = merge(left->next, right, BY_ID, reversesort);
        } else {
            result = right;
            result->next = merge(left, right->next, BY_ID, reversesort);
        }
    }
    }
    return result;
}

material *mergeby_name(material *left, material *right, Sort_t *liste, int index)
{
    material *result;

    if (reversesort) {
        if (my_strcmp(left->name, right->name) >= 0 ) {
            result = left;
            if (left->id == right->id) {
                int index = get_sortype_index(sortype, BY_NAME);
            if (index != -1) {
                result->next = merge(left->next, right, sortype[index], reversesort);
            } else {
                result->next = merge(left->next, right, BY_NAME, reversesort);
            }
            result->next = merge(left->next, right, BY_NAME, reversesort);
        } else {
            result = right;
            result->next = merge(left, right->next, BY_NAME, reversesort);
        }
    } else {
        if (my_strcmp(left->name, right->name) <= 0) {
            result = left;
            if (left->id == right->id) {
                int index = get_sortype_index(sortype, BY_NAME);
            if (index != -1) {
                result->next = merge(left->next, right, sortype[index], reversesort);
            } else {
                result->next = merge(left->next, right, BY_NAME, reversesort);
            }
            result->next = merge(left->next, right, BY_NAME, reversesort);
        } else {
            result = right;
            result->next = merge(left, right->next, BY_NAME, reversesort);
        }
    }
    }
    return result;
}

material *mergeby_type(material *left, material *right, Sort_t *liste, int index)
{
    material *result;

    if (liste[index]->) {
        if (my_strcmp(left->type, right->type) >= 0) {
            result = left;
            if (left->id == right->id) {
                int index = get_sortype_index(sortype, BY_TYPE);
            if (index != -1) {
                result->next = merge(left->next, right, sortype[index], reversesort);
            } else {
                result->next = merge(left->next, right, BY_TYPE, reversesort);
            }
            result->next = merge(left->next, right, BY_TYPE, reversesort);
        } else {
            result = right;
            result->next = merge(left, right->next, BY_TYPE, reversesort);
        }
    } else {
        if (my_strcmp(left->type, right->type) <= 0) {
            result = left;
            if (left->id == right->id) {
                int index = get_sortype_index(sortype, BY_TYPE);
            if (index != -1) {
                result->next = merge(left->next, right, sortype[index], reversesort);
            } else {
                result->next = merge(left->next, right, BY_TYPE, reversesort);
            }
            result->next = merge(left->next, right, BY_TYPE, reversesort);
        } else {
            result = right;
            result->next = merge(left, right->next, BY_TYPE, reversesort);
        }
        }
    }
    }
    return result;
}


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

int sortlist(material **element, Sort_t *sort_liste)
{
    material* leftside;
    material* rightside;

    if (*element == NULL || (*element)->next == NULL) {
        return 0;
    }
    splitlist(*element, &leftside, &rightside);
    sortlist(&leftside, sort_liste);
    sortlist(&rightside, sort_liste);
    *element = merge(leftside, rightside, sort_liste);
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
    Sort_t *sort_type_list = malloc(sizeof(Sort_t)*3);
    int j = 0;
    for (int i = 0; i < 3; i++) {
        sort_type_list[i].reverse = false;
    }
    if (shop_t == NULL || shop_t->first == NULL) {
        my_printf("The list is empty, impossible to sort\n");
        return 84;
    }
    for (int i  = 0; i < 3 && args[i] != NULL; i++) {
        sort_type_list[j].sorttype = getsorttype(args[i]);
        if (error_handling(args, sort_type_list[j].sorttype)) {
            return 84;
        }
        if (args[i + 1] != NULL && my_strcmp(args[i + 1], "-r") == 0) {
            sort_type_list[j].reverse = true;
        } else {
            j++;
        }
    }
    sortlist(&(shop_t->first), sort_type_list);
    return 0;
}
