# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yothmani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 16:03:58 by yothmani          #+#    #+#              #
#    Updated: 2023/10/12 03:28:15 by yothmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME = so_long

# Compilateur et drapeaux de compilation
CC = gcc
# CFLAGS = -g
CFLAGS = -Wall -Wextra -Werror -g

# Répertoires
SRC_DIR = src
LIB_DIR = lib
INCLUDES_DIR = includes
LIBFT_DIR = $(LIB_DIR)/libft

# Fichiers source et objet
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

# Chemin vers les fichiers d'en-tête
INCLUDES = -I$(INCLUDES_DIR) -I$(LIBFT_DIR)

MLX42_DIR = lib/MLX42
MLX42_BUILD_DIR = $(MLX42_DIR)/build

LIB_MLX = -framework Cocoa -framework OpenGL -framework IOKit $(MLX42_DIR)/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

# Cibles
all: libft $(NAME)

$(NAME): $(OBJS)
	-@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft $(LIB_MLX)


# @cd $(MLX42_DIR) && cmake -B build
# 	@cd $(MLX42_DIR) && cmake --build build -j4

%.o: %.c
	-@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft:
	make -C $(LIBFT_DIR)

clean:
	-@rm -f $(OBJS)
	-@make -C $(LIBFT_DIR) clean

fclean: clean
	-@rm -f $(NAME)
	-@make -C $(LIBFT_DIR) fclean

re: fclean all

leaks:
	leaks --atExit -- ./so_long 

run:
	make && ./so_long

one:
	-@cd lib
two:
	git clone https://github.com/codam-coding-college/MLX42.git
three:
	cd MLX42
four:
	cmake -B build
five:
	cmake --build build -j4

.PHONY: all clean fclean re libft

