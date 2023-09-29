/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:00:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/29 17:23:26 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	error(void);

void	ft_render_texture_img(t_map *map, t_textures *info, int x, int y)
{
	if (map->grid[y][x] == '1')
	{
		if (mlx_image_to_window(info->mlx, info->img_wall, x * SIZE_IMG, y
				* SIZE_IMG) < 0)
			error();
	}
	if (map->grid[y][x] == 'P')
	{
		if (mlx_image_to_window(info->mlx, info->img_player, x * SIZE_IMG, y
				* SIZE_IMG) < 0)
			error();
	}
	if (map->grid[y][x] == '0')
	{
		if (mlx_image_to_window(info->mlx, info->img_field, x * SIZE_IMG, y
				* SIZE_IMG) < 0)
			error();
	}
	if (map->grid[y][x] == 'C')
	{
		if (mlx_image_to_window(info->mlx, info->img_ball, x * SIZE_IMG, y
				* SIZE_IMG) < 0)
			error();
	}
	if (map->grid[y][x] == 'E')
	{
		if (mlx_image_to_window(info->mlx, info->img_exit, x * SIZE_IMG, y
				* SIZE_IMG) < 0)
			error();
	}
}

void	ft_create_texture(t_textures *info)
{
	info->texture_player = mlx_load_png("includes/chuki.png");
	info->texture_wall = mlx_load_png("includes/wall.png");
	info->texture_field = mlx_load_png("includes/field.png");
	info->texture_ball = mlx_load_png("includes/ball.png");
	info->texture_exit = mlx_load_png("includes/Exit.png");
	if (!info->texture_player)
		error();
	if (!info->texture_wall)
		error();
	if (!info->texture_field)
		error();
	if (!info->texture_ball)
		error();
	if (!info->texture_exit)
		error();
	info->img_player = mlx_texture_to_image(info->mlx, info->texture_player);
	info->img_wall = mlx_texture_to_image(info->mlx, info->texture_wall);
	info->img_field = mlx_texture_to_image(info->mlx, info->texture_field);
	info->img_ball = mlx_texture_to_image(info->mlx, info->texture_ball);
	info->img_exit = mlx_texture_to_image(info->mlx, info->texture_exit);
	mlx_resize_image(info->img_player, SIZE_IMG,  SIZE_IMG);
	mlx_resize_image(info->img_wall, SIZE_IMG,  SIZE_IMG);
	mlx_resize_image(info->img_field, SIZE_IMG,  SIZE_IMG);
	mlx_resize_image(info->img_ball, SIZE_IMG,  SIZE_IMG);
	mlx_resize_image(info->img_exit, SIZE_IMG,   SIZE_IMG);
}

void	ft_render_winwow(t_map *map)
{
	size_t		x;
	size_t		y;
	t_textures	info;

	// t_textures *info;
	if (!(info.mlx = mlx_init((map->width) * SIZE_IMG, map->height * SIZE_IMG, "MLX42", true)))
	{
		puts(mlx_strerror(10));
		return ;
	}
	ft_create_texture(&info);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_render_texture_img(map, &info, x, y);
			x++;
		}
		y++;
	}
	mlx_loop(info.mlx);
	mlx_delete_texture(info.texture_player);
	mlx_delete_texture(info.texture_wall);
	mlx_delete_texture(info.texture_field);
	mlx_delete_texture(info.texture_ball);
	mlx_delete_texture(info.texture_exit);
}

int	show_command(void)
{
	char	c;
	int		command;

	printf("W / ⬆    - UP \n");
	printf("S / ⬇    - DOWN \n");
	printf("A / ◀️		- LEFT \n");
	printf("D / ▶️ 		- RIGHT \n");
	printf("Esc       - Exit \n");
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

void	init_game(char *file_name, t_map *mat)
{
	int	fd;

	fd = open_file(file_name);
	if (fd < 0)
		perror("Error openning file \n");
	if (parse_file(mat, fd))
		perror("Error Parsing file \n");
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
	t_textures info;
	while (true)
	{
		// mlx_key_hook(info.mlx, &move, NULL);
		system("clear");
		printf(" \n    Collectables  %i/%i \n", player->count_c, mat->count_c);
		// show_grid(mat);
		ft_render_winwow(mat);
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
			if (mat->grid[player->y][player->x] == 'C')
				player->count_c = player->count_c + 1;
			if (player->prev_y > 0)
				mat->grid[player->prev_y][player->prev_x] = '0';
		}
		mat->grid[player->y][player->x] = 'P';
	}
}

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	// exit(EXIT_FAILURE);
	exit(0);
}

char	**ft_create_render_map(t_map *mat, int fd)
{
	char	**table;
	char	*str;
	int		i;

	table = ft_calloc(sizeof(char *), (mat->height + 1)); //height
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		table[i] = str;
		str = get_next_line(fd);
		i++;
	}
	return (table);
}

int	main(void)
{
	char		*file_name;
	t_map		mat;
	t_player	player;

	//  int			input;
	// int			fd;
	file_name = "src/map.ber";
	init_map(&mat);
	init_game(file_name, &mat);
	init_player(&player, mat);
	update_game(&mat, &player);
	// show_grid(&mat);
	//  input = show_command();
	//  printf("======%i\n", input);
	// fd = open(file_name, O_RDONLY);
	// mat.grid = ft_create_render_map(&mat, fd);
	// close(fd);
	// ft_render_winwow(&mat);
}
