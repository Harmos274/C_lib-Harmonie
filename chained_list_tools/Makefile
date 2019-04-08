##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make some files
##

CC = gcc

NAME = test_chlist_tools

TEST_DIR = ./tests/

SRC_FILES = create_chained_list.c \
			print_chained_list.c \
			supr_chained_list.c \
			../str_tools/my_putstr.c \
			../str_tools/my_strdup.c \
			../str_tools/my_strlen.c

SRC_TESTS = cirtest_create_chained_list.c \
			critest_print_chained_list.c

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_TESTS = $(addprefix $(TEST_DIR), $(SRC_TESTS:.c=.o))

override CFLAGS = -W -Wextra -Werror
LDFLAGS = -lcriterion

$(NAME) : $(OBJ_TESTS) $(OBJ_FILES)
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS)
	./$@

all : $(NAME)

clean :
	find -type f -name "*.o" -delete

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
