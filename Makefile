# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/08 13:16:50 by oearlene          #+#    #+#              #
#    Updated: 2019/12/08 13:41:38 by oearlene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

HED = $(wildcard *.h)

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -c -MD $< -o $@

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

include $(wildcard *.d)

clean:
	/bin/rm -rf $(OBJ)
	/bin/rm -rf $(wildcard *.d)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
