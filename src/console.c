/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:34:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/01 01:39:09 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	show_command(void)
{
	char	c;
	int		command;

	printf("W / ⬆   - UP \n");
	printf("S / ⬇   - DOWN \n");
	printf("A / ◀️   - LEFT \n");
	printf("D / ▶️   - RIGHT \n");
	printf("Esc     - Exit \n");
	printf("choose a direction : \n");
	scanf("%c", &c);
	command = c;
	if (command != 'w' && command != 'W' && command != 'A' && command != 'a'
		&& command != 's' && command != 'S' && command != 'D' && command != 'd'
		&& command != 27 && command != 113 && command != 10)
	{
		printf("Invalid direction! \n");
		return (-2);
	}
	return (command);
}

void	update_game(t_map *mat, t_player *player, t_player *enemy)
{
	int		input;
	int		input_e;
	time_t	t;

	srand((unsigned)time(&t));
	// t_textures info;
	while (true)
	{
		// mlx_key_hook(info.mlx, &move, NULL);
		system("clear");
		printf(" \n    Collectables  %i/%i \n", player->count_c, mat->count_c);
		input_e = rand() % 4;
		move_auto(enemy, mat, input_e);
		show_grid(mat);
		// ft_render_winwow(mat);
		input = show_command();
		if (input < 0)
			perror("Error Invalid direction \n");
		else if (input == 27)
			break ;
		else if (can_move(player, mat, input))
		{
			move(player, input);
			if (mat->grid[player->y][player->x] == 'E')
			{
				printf("you won!\n");
				break ;
			}
			if ( mat->grid[player->y][player->x] == 'M')
			{
				printf("you Lost!\n");
				break ;
			}
			if (mat->grid[player->y][player->x] == 'C')
				player->count_c = player->count_c + 1;
			if (player->prev_y > 0)
				mat->grid[player->prev_y][player->prev_x] = '0';
			if (enemy->prev_y > 0)
				mat->grid[enemy->prev_y][enemy->prev_x] = '0';
		}
		mat->grid[player->y][player->x] = 'P';
		mat->grid[enemy->y][enemy->x] = '*';
	}
}
