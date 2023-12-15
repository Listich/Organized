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

material *merge(material *leftside, material *rightside, int sortype,
    bool reversesort)
{
    material *result = NULL;

    if (leftside == NULL) {
        return rightside;
    } else if (rightside == NULL) {
        return leftside;
    }
    switch (sortype) {
    case BY_ID:
        result = mergeby_id(leftside, rightside, reversesort);
        break;
    case BY_NAME:
        result = mergeby_name(leftside, rightside, reversesort);
        break;
    case BY_TYPE:
        result = mergeby_type(leftside, rightside, reversesort);
        break;
    }
    return result;
}

material *mergeby_id(material *left, material *right, bool reversesort)
{
    material *result = NULL;

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

material *mergeby_name(material *left, material *right, bool reversesort)
{
    material *result;

    if (reversesort) {
        if (my_strcmp(left->name, right->name) > 0) {
            result = left;
            result->next = merge(left->next, right, BY_NAME, reversesort);
        } else {
            result = right;
            result->next = merge(left, right->next, BY_NAME, reversesort);
        }
    } else {
        if (my_strcmp(left->name, right->name) < 0) {
            result = left;
            result->next = merge(left->next, right, BY_NAME, reversesort);
        } else {
            result = right;
            result->next = merge(left, right->next, BY_NAME, reversesort);
        }
    }
    return result;
}

material *mergeby_type(material *left, material *right, bool reversesort)
{
    material *result;

    if (reversesort) {
        if (my_strcmp(left->type, right->type) > 0) {
            result = left;
            result->next = merge(left->next, right, BY_TYPE, reversesort);
        } else {
            result = right;
            result->next = merge(left, right->next, BY_TYPE, reversesort);
        }
    } else {
        if (my_strcmp(left->type, right->type) < 0) {
            result = left;
            result->next = merge(left->next, right, BY_TYPE, reversesort);
        } else {
            result = right;
            result->next = merge(left, right->next, BY_TYPE, reversesort);
        }
    }
    return result;
}
