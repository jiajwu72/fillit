#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwu <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 12:56:02 by jwu               #+#    #+#              #
#    Updated: 2017/11/28 11:44:15 by jwu              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# GCC
CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

# COMPILATION
SRC = checktetri.c create_tetri.c main.c map.c read_file.c resolve.c \
tetri_resolve.c checkfillit.c
OBJ = $(SRC:.c=.o)
NAME = fillit

# LIBFT
LIB = libft/libft.a

# PHONY
.PHONY: all clean fclean re

# RULES
all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -f *.o
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all
