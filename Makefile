##
## EPITECH PROJECT, 2023
## B-CPE-110-TLS-1-1-organized-serena.kifoula
## File description:
## Makefile
##


NAME = organized

SRC = organized.c\
	  sort.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra


all: $(NAME)

debug: fclean
	 CFLAGS=-g3 $(MAKE)

clean:
		find . -type f -name '*~' -delete
		find . -type f -name '#*#' -delete
		find . -type f -name '*.o' -delete

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

$(NAME) : $(OBJ)
		gcc -o $(NAME) $(OBJ) -L./libshell -lshell

test: $(NAME)
		cat test_basic.txt | ./$(NAME)
		cat test_deletion.txt | ./$(NAME)
		cat test_sorting.txt | ./$(NAME)
		cat test_full.txt | ./$(NAME)

.PHONY : all re fclean clean test
