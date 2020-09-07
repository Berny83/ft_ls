# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 17:12:11 by aagrivan          #+#    #+#              #
#    Updated: 2020/09/02 18:29:03 by aagrivan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = ft_get_flags.c \
		ft_print_di.c \
		ft_print_o.c \
		ft_print_scp.c \
		ft_print_u.c \
		ft_print_x.c \
		ft_printf.c \
		ft_support.c \
		attributes.c \
		init_f.c \
		mem_alloc.c \
		pow_2.c \
		pow_5.c \
		print_f.c \
		round.c \
		round_change.c \
		nan_inf.c \
		ft_print_other.c
SRC_DIR = ft_printf/
SRCS_P = $(addprefix $(SRC_DIR),$(SRCS))

LIB_F = ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isblank.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_isxdigit.c\
		ft_itoa.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_range.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strrev.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_swap.c\
		ft_tolower.c\
		ft_toupper.c\
		get_next_line.c\
		ft_countwords.c\
		ft_atoi_base.c\
		ft_itoa_base.c \
		ft_strndup.c \
		ft_itoa_base.c \
		ft_itoa_base_address16.c \
		ft_itoa_base_ll.c \
		ft_itoa_base_ll_pos.c \
		ft_itoa_base_ull.c \
		ft_putunbr.c
LIBF_DIR = srcs/
LIBF_P = $(addprefix $(LIBF_DIR),$(LIB_F))

HEAD_DIR = includes/
HEAD_P = $(addprefix $(HEAD_DIR),ft_printf.h)
HEAD_LP = $(addprefix $(HEAD_DIR),libft.h)

OBJLIBDIR = obj_lib/
OBJ_LIBP = $(addprefix $(OBJLIBDIR),$(LIB_F:%.c=%.o))

OBJDIR = obj_printf/
OBJ_P = $(addprefix $(OBJDIR),$(SRCS:%.c=%.o))

vpath %.c srcs ft_printf
vpath %.h includes

# COLOR
GREEN = \033[0;32m
RED = \033[0;31m
BASE = \033[0m

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_LIBP) $(OBJ_P)
	@ar rc $(NAME) $(OBJ_P) $(OBJ_LIBP)
	@echo "$(GREEN)$(NAME) was created.$(BASE)"
	@ranlib $(NAME)

$(OBJDIR)%.o: $(SRC_DIR)%.c $(HEAD_P)
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -I $(HEAD_DIR) -c $< -o $@

$(OBJLIBDIR)%.o: $(LIBF_DIR)%.c $(HEAD_LP)
	@mkdir -p $(OBJLIBDIR)
	@$(CC) $(FLAGS) -I $(HEAD_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJDIR) $(OBJLIBDIR)
	@echo "$(RED)all object files were deleted.$(BASE)"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIB)
	@echo "$(RED)$(NAME) was deleted.$(BASE)"

re: fclean all
