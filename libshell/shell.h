/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H
    #define BY_NAME 1
    #define BY_ID 2
    #define BY_TYPE 3
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stdbool.h>

typedef struct material_s {
    char type[256];
    char name[256];
    int id;
    struct material *next;
}material;

typedef struct shop_s {
    material *first;
    int nb_elements;
}shop;

// To be implemented
int add(void *data, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data, char **args);

// Already implemented
int workshop_shell(void *data);

material *mergeby_id(material* left, material* right, bool reversesort);
material *mergeby_name(material* left, material* right, bool reversesort);
material *mergeby_type(material* left, material* right, bool reversesort);
int add_handling(material *new_element);
int add_handling_new(char **args, int i);
int error_handling_del(char **args);
int error_handling_del2(shop *element);
int print_del(material *current);
void printf_add(material *new_element);
shop *initialisation(void);
int getsorttype(char *arg);
int sortlist(material **element, int sortType, bool reverseSort);
int error_handling(char **args, int sort_type);

#endif /* SHELL_H */
