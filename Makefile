# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 18:51:54 by mpascual          #+#    #+#              #
#    Updated: 2025/07/24 13:34:23 by mapascua         ###   ########.fr        #
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
LIBFT_DIR	= ./lib/libft
LIBFT		= libft.a
MLX_DIR		= ./lib/minilibx-linux
MLX			= libmlx_Linux.a
SRC 		= main.c draw.c read.c utils.c store_map.c
BONUS_SRC	= main_bonus.c draw.c read.c utils.c store_map.c
HEADERS		= fdf.h $(LIBFT_DIR)/$(LIBFT)
OS			= $(shell uname)
SCREEN_RESX	= $(shell xdpyinfo | grep 'dimensions' | cut -d ' ' -f7 | cut -d 'x' -f1)
SCREEN_RESY	= $(shell xdpyinfo | grep 'dimensions' | cut -d ' ' -f7 | cut -d 'x' -f2)

ifdef WITH_BONUS
	SRCS = $(BONUS_SRC)
else
	SRCS = $(SRC)
endif

OBJS			= $(SRCS:.c=.o)
CFLAGS			= -Wall -Wextra -Werror

# Flags for minilibx compilation in mac and linux
ifeq ($(OS), Linux)
	MLX_FLAGS	= -Lmlx_linux -L. $(MLX_DIR)/$(MLX) -Imlx_linux -lXext -lX11 -lm -lz
else
	MLX			= libmlx.a
	MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit
endif

all: compile_lib $(NAME)

$(NAME): $(OBJS) $(HEADER)

	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) -L. $(LIBFT_DIR)/$(LIBFT) -D SCREEN_RES_X=$(SCREEN_RESX) -D SCREEN_RES_Y=$(SCREEN_RESY)
	@echo "$(GREEN)$(NAME) created ✓${CLR_RMV}"

$(OBJS): $(SRCS)
		$(CC) $(CFLAGS) -c $(SRCS)

debug: compile_lib
	@echo $(SCREEN_RESX)
	@echo $(SCREEN_RESY)
	@echo "$(GREEN)--DEBUG MODE--\nCompilation ${CLR_RMV}of ${YELLOW}$(NAME)${CLR_RMV}..."
	$(CC) $(CFLAGS) -g $(SRCS) -o $(NAME) $(MLX_FLAGS) -L. $(LIBFT_DIR)/$(LIBFT) -fsanitize=address -D SCREEN_RES_X=$(SCREEN_RESX) -D SCREEN_RES_Y=$(SCREEN_RESY)
	@echo "$(GREEN)$(NAME) created ✓${CLR_RMV}"

compile_lib:
		cd $(LIBFT_DIR) && $(MAKE)
		cd $(MLX_DIR) && $(MAKE)

clean:
		rm -rf $(OBJS)
		rm -rf $(BONUS_SRC:.c=.o)
		cd $(LIBFT_DIR) && $(MAKE) clean
		cd $(MLX_DIR) && $(MAKE) clean

fclean: clean
		rm -rf $(LIBFT_DIR)/$(LIBFT)
		rm -rf $(NAME)

bonus:
	$(MAKE) WITH_BONUS=1

norme:
		@norminette $(SRCS) $(HEADERS) 

re: fclean all

.PHONY: all re clean fclean
