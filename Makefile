# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/16 15:31:02 by aagrivan          #+#    #+#              #
#    Updated: 2020/09/02 18:49:19 by aagrivan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES = validate.c display_ls.c ft_ls.c main.c ls_error.c 
HEADER = includes/
LIB = lib/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -I $(HEADER) $(SOURCES) $(LIB) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all