# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 16:03:58 by yothmani          #+#    #+#              #
#    Updated: 2023/10/16 15:16:16 by yothmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= so_long
NAME_BONUS 			= so_long_bonus

CC 					= gcc
CFLAGS 				= -Wall -Wextra -Werror

RM					= rm -rf

LIBFT 				= $(LIBFT_DIR)/libft.a
MLX 				= $(MLX_DIR)/libmlx42.a

SRC_DIR 			= src
BONUS_DIR 			= bonus/src_bonus
INC_DIR 			= includes
INCS_DIR_BONUS		= bonus/bonus_includes
LIBFT_DIR 			= lib/libft
MLX_DIR 			= lib/MLX42/build

INC 				= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
INC_BONUS 			= -I$(INCS_DIR_BONUS) -I$(LIBFT_DIR) -I$(MLX_DIR)



SRC = $(SRC_DIR)/file.c $(SRC_DIR)/game.c $(SRC_DIR)/main.c $(SRC_DIR)/img_and_textures.c \
      $(SRC_DIR)/map.c $(SRC_DIR)/mlx_clean_up.c $(SRC_DIR)/mlx_utils.c \
      $(SRC_DIR)/moves.c $(SRC_DIR)/parse_utils.c $(SRC_DIR)/parse.c \
      $(SRC_DIR)/player.c $(SRC_DIR)/possible_maps.c


BONUS_SRC = $(BONUS_DIR)/enemy_bonus.c $(BONUS_DIR)/file_bonus.c $(BONUS_DIR)/game_bonus.c \
            $(BONUS_DIR)/img_and_textures_bonus.c $(BONUS_DIR)/main_bonus.c $(BONUS_DIR)/map_bonus.c \
            $(BONUS_DIR)/mlx_clean_up_bonus.c $(BONUS_DIR)/moves_bonus.c $(BONUS_DIR)/parse_bonus.c \
            $(BONUS_DIR)/parse_utils_bonus.c $(BONUS_DIR)/possible_maps_bonus.c


SRC 				= $(wildcard $(SRC_DIR)/*.c)
BONUS_SRC 			= $(wildcard $(BONUS_DIR)/*.c)
OBJ 				= $(SRC:.c=.o)
BONUS_OBJ 			= $(BONUS_SRC:.c=.o)

MLX42_REPO = https://github.com/codam-coding-college/MLX42.git

all: install $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ $(INC) -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit
	@printf $(CUT)$(CUT)$(CUT)$(CUT)
	@echo "`tput bold``tput setaf 5` 🏥 Welcome to your mission, Dr Hero! This is the calm before the `tput setaf 2`bonus `tput bold``tput setaf 5`part storm. Collect those vaccines 💉 `tput setaf 6`and don't forget to reach the ambulance for victory! 🚑💨`tput sgr0`"
	

$(NAME_BONUS): $(BONUS_OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ $(INC_BONUS) -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit
	@printf $(CUT)$(CUT)$(CUT)$(CUT)
	@echo $(BOLD)$(L_PURPLE) 🦸‍♂️ Get ready, Dr Hero! Your mission to defeat the $(BOLD)$(GREEN)COVID 🦠 $(BOLD)$(L_PURPLE)virus is about to begin!$(GREEN) Best of luck, savior of the world! 💪💥$(RESET)
	

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INC) $(INC_BONUS)
	@echo "Compiled $<"

MLX42_EXISTS := $(wildcard lib/MLX42)

install:
	@if [ -d "lib/MLX42" ]; then \
    	echo $(BOLD)$(PINK)" MLX42 already exists\n Nothing to be done for 'all' "; \
	else \
    	cd lib && git clone $(MLX42_REPO) MLX42; \
    fi
	@cd lib/MLX42 && cmake -B build > /dev/null 2>&1
	@cd lib/MLX42 && cmake --build build -j4 > /dev/null 2>&1


norm :
	@echo $(BOLD)$(PINK)" Mandatory part!"$(MINT)
	@norminette $(SRC) $(INC_DIR)
	@echo $(BOLD)$(PINK)" Bonus part!"$(MINT)
	@norminette $(BONUS_SRC) $(INCS_DIR_BONUS)


leaks:
	leaks --atExit -- ./so_long  src/maps/batmap.ber

leaks_bonus:
	leaks --atExit -- ./so_long_bonus  bonus/maps/batmap.ber

clean :
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@printf $(CUT)$(CUT)
	@$(RM) $(OBJ) $(BONUS_OBJ) so_long.dSYM
	@echo $(BOLD)$(L_PURPLE)"Cleaned objects and executables!" ... 🧹🗑️$(RESET)

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS) so_long.dSYM
	@printf $(CUT)$(CUT)
	@echo $(BOLD)$(L_PURPLE) ✨so_long✨ $(PINK)All cleaned up! ....🧹🗑️$(RESET)

re: fclean all bonus

.PHONY: all bonus clean fclean re

# ######################### Color #########################

GREEN="\033[32m"
MINT="\033[38;5;51m"
L_PURPLE="\033[38;5;55m"
MAUVE="\033[38;5;147m"
PINK="\033[38;5;175m"
RESET="\033[0m"
BOLD="\033[1m"
UP = "\033[A"
DOWN = "\033[B"
RIGHT = "\033[C"
LEFT = "\033[D"
CUT = "\033[K"
SAVE = "\033[s"
RESTORE = "\033[u"

