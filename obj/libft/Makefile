# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yothmani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 13:17:11 by yothmani          #+#    #+#              #
#    Updated: 2023/09/13 17:49:53 by yothmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# NAME = libft.a

# SRCS		= 	 ft_bzero.c ft_isalnum.c ft_isalpha.c ft_memset.c\
# ft_isdigit.c ft_strlen.c ft_isprint.c ft_memcpy.c ft_toupper.c ft_tolower.c\
# ft_memmove.c ft_memchr.c ft_memcmp.c ft_strncmp.c ft_strrchr.c ft_strlcpy.c\
# ft_strlcat.c ft_atoi.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c\
# ft_strjoin.c ft_strtrim.c ft_split.c ft_putnbr_fd.c ft_strmapi.c\
# ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
# ft_putnbr_fd.c ft_strmapi.c  ft_strchr.c ft_isascii.c ft_striteri.c get_next_line.c\


# BONS		=	ft_lstmap_bonus.c ft_lstiter_bonus.c ft_lstclear_bonus.c\
# ft_lstdelone_bonus.c ft_lstadd_back_bonus.c ft_lstsize_bonus.c\
# ft_lstlast_bonus.c ft_lstadd_front_bonus.c ft_lstnew_bonus.c\
# ft_putstr.c ft_putchar.c\

# GCC			=	@gcc -Wall -Wextra -Werror

# OBJS		=	$(SRCS:.c=.o)

# BONSOBJ		=	$(BONS:.c=.o)

# INCLUDES	=	./

# all: $(NAME)

# $(NAME):	$(SRCS) libft.h
# 		$(GCC) -I$(INCLUDES) -c $(SRCS)
# 		-@ar rc $(NAME) $(OBJS)
# 		-@ranlib $(NAME)
# bonus:		$(BONS) $(SRCS) libft.h
# 		$(GCC) -I$(INCLUDES) -c $(BONS)	$(SRCS)
# 		-@ar rc $(NAME) $(BONSOBJ) $(OBJS)
# 		-@ranlib $(NAME)
# clean:  
# 			-@$(RM) $(OBJS)	$(BONSOBJ)
# fclean:     clean
# 			-@$(RM) $(NAME)
# re:			fclean all

# .PHONY:		all clean fclean re bonus

# Nom du compilateur
CC = gcc

# Drapeaux de compilation
CFLAGS = -Wall -Wextra -Werror

# Nom de la bibliothèque
NAME = libft.a

# Répertoires
SRC_DIR = src
OBJ_DIR = obj
INCLUDES = includes

# Fichiers source
SRCS = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_memset.c \
       ft_isdigit.c ft_strlen.c ft_isprint.c ft_memcpy.c \
       ft_toupper.c ft_tolower.c ft_memmove.c ft_memchr.c \
       ft_memcmp.c ft_strncmp.c ft_strrchr.c ft_strlcpy.c \
       ft_strlcat.c ft_atoi.c ft_strnstr.c ft_calloc.c \
       ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
       ft_split.c ft_putnbr_fd.c ft_strmapi.c ft_itoa.c \
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
       ft_strchr.c ft_isascii.c ft_striteri.c get_next_line.c

# Fichiers objets
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

# Création de la bibliothèque
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

# Cible principale
all: $(NAME)

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJ_DIR)

# Nettoyage de la bibliothèque et des fichiers objets
fclean: clean
	rm -f $(NAME)

# Recréation de la bibliothèque
re: fclean all

# Création du répertoire d'objets si nécessaire
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Déclaration des cibles ne nécessitant pas de fichiers physiques
.PHONY: all clean fclean re
