##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make some files
##

CC = gcc

NAME = test_strtools

TEST_DIR = ./tests/

SRC_FILES = clean_str.c \
			my_getnbr.c \
			my_itoa.c \
			my_put_nbr.c \
			my_putstr.c \
			my_revstr.c \
			my_strcomp.c \
			my_strconc.c \
			my_str_isnum.c \
			my_strlen.c \
			my_strncpy.c \
			my_str_to_word_array.c \
			my_strdup.c

SRC_TESTS = critest_str_to_wordarr.c \
			critest_strconc.c \
			critest_atoi_itoa.c \
			critest_strncpy.c

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_TESTS = $(addprefix $(TEST_DIR), $(SRC_TESTS:.c=.o))

CFLAGS = -W -Wextra -Werror
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
