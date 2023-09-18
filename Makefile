# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 16:03:58 by yothmani          #+#    #+#              #
#    Updated: 2023/09/18 13:39:27 by yothmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Compilateur et drapeaux de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Répertoires
SRC_DIR = src
LIB = lib
INCLUDES = includes
LIBFT_PATH = lib/libft/inc
HEADER_SL = -I$(INCLUDES)/
HEADER_LFT = -I$(LIB)/libft/inc

# Fichiers source et objet
SRCS = main.c parsing .c map_check.c\
OBJS = $(patsubst $(SRC_DIR)/%.c, $(LIB)/%.o, $(SRCS))

libft:
	-@make -C LIB/libft all
gcc = $(CC) $(CFLAGS)
# Cibles
all: libft $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -L$(LIBFT_PATH)/libft.a $(HEADER_SL) $(HEADER_LFT) $(OBJS) -o 

$(LIB)/%.o: $(SRC_DIR)/%.c | $(LIB)
	@gcc $(INCLUDES) -c $< -o $@

$(LIB):
	mkdir -p $(LIB)

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(RM) -r $(LIB)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
