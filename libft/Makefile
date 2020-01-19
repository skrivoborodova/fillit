# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oearlene <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 22:51:45 by oearlene          #+#    #+#              #
#    Updated: 2019/12/08 13:09:48 by oearlene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

HED = $(wildcard *.h)

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c -MD $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) $(HED)

include $(wildcard *.d)

clean:
	@/bin/rm -rf $(OBJ)
	@/bin/rm -rf $(wildcard *.d)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
