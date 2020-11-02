# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/16 15:31:02 by aagrivan          #+#    #+#              #
#    Updated: 2020/11/02 17:12:44 by aagrivan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = srcs/
SRCS =	main.c \
		validate.c\
		ft_ls.c\
		sorting.c\
		sort_ft.c\
		ls_error.c\
		display_dir.c\
		display_dir_ftsupport.c\
		display_file.c\
		display_ls.c\
		display_print.c\
		print.c\
		display_no_file.c
SRCS_P = $(addprefix $(SRCS_DIR),$(SRCS))

HEAD_DIR = includes/
HEAD = ft_ls.h
HEAD_P = $(addprefix $(HEAD_DIR),$(HEAD))

OBJDIR = obj/
OBJ_P = $(addprefix $(OBJDIR),$(SRCS:%.c=%.o))

LIBFT = libft/
LFLAGS = -L $(LIBFT) -lft

vpath %.c srcs lib
vpath %.h includes

# COLOR
GREEN = \033[0;32m
RED = \033[0;31m
BASE = \033[0m

all: $(NAME)

$(NAME): $(OBJ_P)
	@make -C $(LIBFT)
	$(CC) $(FLAGS) $(OBJ_P) $(LFLAGS) -o $(NAME)

$(OBJDIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -I $(LIBFT) -I $(HEAD_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFT) clean
	@echo "$(RED)all object files were deleted.$(BASE)"
	
fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean
	@echo "$(RED)$(NAME) was deleted.$(BASE)"

re: fclean all

.PHONY: all clean fclean re