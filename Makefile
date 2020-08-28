# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/16 15:31:02 by aagrivan          #+#    #+#              #
#    Updated: 2020/08/26 21:34:33 by aagrivan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES = main.c ls_error.c validate.c display_ls.c ft_ls.c srcs/ft_strdup.c srcs/ft_strcpy.c srcs/ft_strcat.c
HEADER = includes/ft_ls.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(HEADER) $(SOURCES) libftprintf.a -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all