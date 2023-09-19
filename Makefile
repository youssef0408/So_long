# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 16:03:58 by yothmani          #+#    #+#              #
#    Updated: 2023/09/19 17:37:19 by yothmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME = so_long

# Compilateur et drapeaux de compilation
CC = gcc
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

# Cibles
all: libft $(NAME)

$(NAME): $(OBJS)
	-@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

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

.PHONY: all clean fclean re libft

