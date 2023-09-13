# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yothmani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 16:03:58 by yothmani          #+#    #+#              #
#    Updated: 2023/09/13 17:39:06 by yothmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilateur et drapeaux de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Noms des exécutables
NAME = so_long
LIBFT = libft/libft.a

# Répertoires
SRC_DIR = src
OBJ_DIR = obj
INCLUDES = includes

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
	
# Fichiers source et objet
SRCS = main.c map_check.c parsing.c
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Dépendances
LIBFT_PATH = libft
LIBFT_INC = -I$(LIBFT_PATH)/$(INCLUDES)
LIBFT_LINK = -L$(LIBFT_PATH) -lft

# Cibles
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LINK)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LIBFT_INC) -I$(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
