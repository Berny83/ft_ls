# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/16 15:31:02 by aagrivan          #+#    #+#              #
#    Updated: 2020/08/16 16:52:27 by aagrivan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES = main.c
HEADER = ft_ls.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(SOURCES) 111111/libftprintf.a -I includes/ -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all