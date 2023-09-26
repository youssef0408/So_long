/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:00:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/26 18:24:37 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	main(void)
{
	// char		*file_name;
	// t_map		mat;
	// t_player	player;
	// int			input;
	mlx_t* mlx;

	// init_map(&mat);
	// file_name = "src/map.ber";
	// init_game(file_name, &mat);
	// init_player(&player, mat);

	
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	
	mlx_texture_t* texture = mlx_load_png("includes/chuki.png");
	if (!texture)
        error();
	
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
        error();

	if (mlx_image_to_window(mlx, img, 0, 8) < 0)
        error();

	mlx_loop(mlx);
		
	// show_grid(&mat);
	// update_game(&mat, &player);
	// input = show_command();
	// printf("======%i\n", input);
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}




int	show_command(void)
{
	char	c;
	int		asciiValue;

	printf("W - UP \n");
	printf("S - DOWN \n");
	printf("A - LEFT \n");
	printf("D - RIGHT \n");
	printf("Q - Exit \n");
	printf("Enter a character to find its ASCII value: ");
	scanf("%c", &c);
	asciiValue = c;
	if (asciiValue != 87 && asciiValue != 65 && asciiValue != 83
		&& asciiValue != 68 && asciiValue != 119 && asciiValue != 97
		&& asciiValue != 115 && asciiValue != 100 && asciiValue != 81
		&& asciiValue != 113 && asciiValue != 10)
		return (-2);
	return (asciiValue);
}

void	init_game(char *file_name,
				t_map *mat)
{
	int	fd;

	fd = open_file(file_name);
	if (fd < 0)
		perror("Error  Open file \n");
	if (parse_file(mat, fd))
		perror("Error Parsig file \n");
}

size_t	real_len(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}



void	update_game(t_map *mat, t_player *player)
{
	int	input;

	while (true)
	{
		fflush(stdout);
		input = show_command();
		printf(" \n    Collectables  %i/%i \n", player->count_c, mat->count_c);
		if (input < 0)
			perror("Error Invalid direction \n");
		else if (input == 27)
			break ;
		else if (can_move(player, mat, input))
		{
			if (mat->grid[player->y][player->x] == 'E')
			{
				if( player->count_c == mat->count_c){
					printf("Congrats!, you won the game .");
					break;	
				}
				if( player->count_c != mat->count_c)
				{
					
				}
				
			}
			
			show_grid(mat);
			move(player, input);
			if (mat->grid[player->y][player->x] == 'C')
				player->count_c = player->count_c + 1;
			if (player->prev_y > 0)
				mat->grid[player->prev_y][player->prev_x] = '0';
		}
		mat->grid[player->y][player->x] = 'P';
	}
}


