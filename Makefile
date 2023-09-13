# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yothmani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 16:03:58 by yothmani          #+#    #+#              #
#    Updated: 2023/09/13 19:19:28 by yothmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Compilateur et drapeaux de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Répertoires
SRC_DIR = src
OBJ_DIR = obj
INCLUDES = includes
LIBFT_PATH = so_long/obj/libft/includes/libft.h

# Fichiers source et objet
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Dépendances
LIBFT_INC = -I$(LIBFT_PATH)/includes
LIBFT_LINK = -L$(LIBFT_PATH) -lft

# Cibles
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_PATH)/libft.a
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBFT_LINK)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LIBFT_INC) -I$(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
