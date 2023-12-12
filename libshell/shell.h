/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H

#define ADD_ELEMENT 1
#define DEL_ELEMENT 2
#define SORT_ELEMENT 3
#define DISP_ELEMENT 4

typedef struct Material
{
    char *type;
    char *name;
    int id;
    int nb_elements; 
    struct Material *next;
}Material;

typedef struct shop
{
    Material *first;
}Shop;


// To be implemented
int add(void *data, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data, char **args);

// Already implemented
int workshop_shell(void *data);

#endif /* SHELL_H */