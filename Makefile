# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yothmani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 14:43:54 by yothmani          #+#    #+#              #
#    Updated: 2023/09/13 15:54:20 by yothmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilateur et drapeaux de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Noms des exécutables
NAME = so_long
LIBFT = libft.a

# Répertoires
SRC_DIR = src
OBJ_DIR = obj
INCLUDES = includes

# Fichiers source et objet
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Dépendances
LIBFT_PATH = libft
LIBFT_INC = -I$(LIBFT_PATH)/$(INCLUDES)
LIBFT_LINK = -L$(LIBFT_PATH) -lft

# Cibles
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_PATH)/$(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LINK)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LIBFT_INC) -I$(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_PATH)/$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
