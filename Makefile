# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 18:51:54 by mpascual          #+#    #+#              #
#    Updated: 2023/05/19 19:38:46 by mpascual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output Colors
CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

# Global Config
NAME		= fdf
LIBFT_DIR	= ./libft
LIBFT		= libft.a
SRC 		= main.c draw.c read.c utils.c store_map.c
SRC_BONUS	=
OS			= $(shell uname)

ifdef WITH_BONUS
	SRCS = $(SRC) $(BONUS_SRC)
else
	SRCS = $(SRC)
endif

OBJS			= $(SRCS:.c=.o)
CFLAGS			= -Wall -Wextra -Werror

# Flags for minilibx compilation in mac and linux
ifeq ($(OS), Linux)
	MLX_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit
endif

all: compile_lib $(NAME)

$(NAME): $(OBJS) $(HEADER)

	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	gcc $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) -L. $(LIBFT_DIR)/$(LIBFT)
	@echo "$(GREEN)$(NAME) created ✓${CLR_RMV}"

$(OBJS): $(SRCS)
		$(CC) $(CFLAGS) -c $(SRCS)

debug: compile_lib
	@echo "$(GREEN)--DEBUG MODE--\nCompilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	$(CC) $(CFLAGS) -g $(SRCS) -o $(NAME) $(MLX_FLAGS) -L. $(LIBFT_DIR)/$(LIBFT) -fsanitize=address,undefined
	@echo "$(GREEN)$(NAME) created ✓${CLR_RMV}"

compile_lib:
		cd $(LIBFT_DIR) && $(MAKE)

clean:
		rm -rf $(OBJS)
		cd $(LIBFT_DIR) && make clean

fclean: clean
		rm -rf $(LIBFT_DIR)/$(LIBFT)
		rm -rf $(NAME)

bonus:
	$(MAKE) WITH_BONUS=1

norme:
		@norminette $(SRCS) fdf.h

re: fclean all

.PHONY: all re clean fclean
