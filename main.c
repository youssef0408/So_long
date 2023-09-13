/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:00:25 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/11 21:48:00 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	init_game();
	return (0);
}

void	init_game(void)
{
	char	*file_name;

	file_name = "./so_long/map.ber";
	//  read file
	// parse file line by line
	parse_file(file_name);
	// generate map array
}

void	update_game(void)
{
	// handle game state
	// handle movement
	// handle pickups
}

bool	parse_file(char *file_path)
{
	int		fd;
	char	*current_line;
	char	*next_line;
	int		is_rect;
	bool	has_error;
	int		line_length;

	has_error = false;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR\n");
		return (true);
	}
	current_line = get_next_line(fd);
	line_length = ft_strlen(current_line);
	if (line_length == 0)
	{
		perror("Error\n");
		free(current_line);
		close(fd);
		return (true);
	}
	while (current_line != NULL && has_error == false)
	{
		if (line_length != ft_strlen((current_line)))
		{
			perror("Error, your map is not rectangular\n");
			has_error = true;
		}
		free(current_line);
		current_line = get_next_line(fd);
		printf("%s\n", current_line);
	}
	free(current_line);
	close(fd);
	return (has_error);
}
