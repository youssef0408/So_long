# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yothmani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 16:03:58 by yothmani          #+#    #+#              #
#    Updated: 2023/10/13 03:13:51 by yothmani         ###   ########.fr        #
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
INCS_DIR_BONUS		= ./bonus/bonus_includes
LIBFT_DIR 			= lib/libft
MLX_DIR 			= lib/MLX42/build

INC 				= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
INC_BONUS 			= -I$(INCS_DIR_BONUS) -I$(LIBFT_DIR) -I$(MLX_DIR)

SRC 				= $(wildcard $(SRC_DIR)/*.c)
BONUS_SRC 			= $(wildcard $(BONUS_DIR)/*.c)					

OBJ 				= $(SRC:.c=.o)
BONUS_OBJ 			= $(BONUS_SRC:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

# $(NAME): $(OBJ) $(LIBFT) $(MLX)
# 	$(CC) $(CFLAGS) -o $@ $^ $(INC) -lglfw -L"/usr/local/lib" -framework Cocoa -framework OpenGL -framework IOKit
# 	@printf $(CUT)$(CUT)
# 	@echo "$(BOLD)$(L_PURPLE) 🏥 Welcome to your mission, Dr Hero! This is the calm before the $(GREEN)bonus $(BOLD)$(L_PURPLE)part storm. Collect those vaccines 💉 $(MINT)and don't forget to reach the ambulance for victory! 🚑$(RESET)"

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ $(INC) -lglfw -L"/usr/local/lib" -framework Cocoa -framework OpenGL -framework IOKit
	@printf $(CUT)$(CUT)
	@echo "`tput bold``tput setaf 5` 🏥 Welcome to your mission, Dr Hero! This is the calm before the `tput setaf 2`bonus `tput bold``tput setaf 5`part storm. Collect those vaccines 💉 `tput setaf 6`and don't forget to reach the ambulance for victory! 🚑💨`tput sgr0`"

$(NAME_BONUS): $(BONUS_OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ $(INC_BONUS) -lglfw -L"/usr/local/lib" -framework Cocoa -framework OpenGL -framework IOKit
	@printf $(CUT)$(CUT)
	@echo $(BOLD)$(L_PURPLE) 🦸‍♂️ Get ready, Dr Hero! Your mission to defeat the $(GREEN)COVID 🦠 $(BOLD)$(L_PURPLE)virus is about to begin!$(GREEN) Best of luck, savior of the world! 💪💥$(RESET)
	
$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INC) $(INC_BONUS)
	@echo $(CUT)$(BOLD)$(MINT) Compiling with $(CFLAGS)...$(RESET)
	@echo $(CUT)$(MAUVE) [$(notdir $^)] to [$(notdir $@)] $(RESET)
	@printf $(UP)$(UP)

norm :
	@norminette $(SRC) $(INC_DIR)

norm_bonus :
	@norminette $(BONUS_SRC) $(INCS_DIR_BONUS)

clean :
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@printf $(CUT)$(CUT)
	@$(RM) $(OBJ) $(BONUS_OBJ) so_long.dSYM

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS) so_long.dSYM
	@printf $(CUT)$(CUT)
	@echo $(BOLD)$(L_PURPLE) ✨so_long✨ $(PINK)All cleaned up! ....🧹🗑️$(RESET)


re: fclean all

.PHONY: all bonus clean fclean re


######################### Color #########################

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

