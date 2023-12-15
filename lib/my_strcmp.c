/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** Reproduce the behavior of the strcmp
*/


int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 != '\0' && (*s1 == s2)) {
        *s1++;
        *s2++;
    }
    if ((*s1 == *s2)) {
        return 0;
    }
    if (*s1 > *s2) {
        return 1;
    }
    if (*s1 < *s2) {
        return -1;
    }
}
