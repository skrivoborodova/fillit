# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oearlene <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/08 13:16:50 by oearlene          #+#    #+#              #
#    Updated: 2020/01/25 00:12:48 by oearlene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

INC_DIR	= ./includes
LIB_DIR	= ./libft

SRC =   main.c \
        read_and_stock.c \
        map.c \
        validation.c \
        solution.c \
        solution_1.c \
        $(LIB_DIR)/*.c

OBJ = $(SRC:.c=.o)

HED = $(INC_DIR)/fillit.h

LIBHDR = $(LIB_DIR)/libft.h

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(HDR) -I $(LIBHDR)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
