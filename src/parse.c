/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:04:34 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/09 20:05:41 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	row_check(char *str, t_map *map)
{
	size_t	col_idx;
	int		result;

	col_idx = 0;
	if (!str)
		return (0);
	if (map->width != real_len(str))
		return (-2);
	if (str[0] != '1' || str[map->width - 1] != '1')
		return (-8);
	while (str[col_idx] && col_idx < map->width - 1)
	{
		result = col_check(str, map, map->height, col_idx);
		if (result < 0)
			return (result);
		col_idx++;
	}
	populate_row(str, map->height, map);
	map->height = map->height + 1;
	return (0);
}

int	col_check(char *str, t_map *map, size_t row_idx, size_t col_idx)
{
	if (map->height == 0 && str[col_idx] != '1')
		return (-9);
	else if (str[col_idx] == 'E')
	{
		if (map->has_e)
			return (-3);
		else
		{
			map->e_x = col_idx;
			map->e_y = row_idx;
			map->has_e = true;
		}
	}
	else if (str[col_idx] == 'P')
	{
		if (map->has_p)
			return (-4);
		else
		{
			map->p_x = col_idx;
			map->p_y = row_idx;
			map->has_p = true;
		}
	}
	else if (str[col_idx] == 'M')
	{
		if (map->has_m)
			return (-69);
		else
		{
			map->m_x = col_idx;
			map->m_y = row_idx;
			map->has_m = true;
		}
	}
	else if (str[col_idx] == 'C')
		map->count_c = map->count_c + 1;
	else if (str[col_idx] != '1' && str[col_idx] != 'M' && str[col_idx] != '0'
			&& str[col_idx] != '\n')
		return (-5);
	return (0);
}

bool	parse_file(t_map *map, int fd)
{
	char	*current_line;
	 char	*previous_line;

	
	 previous_line = NULL;
	current_line = get_next_line(fd);
	if (!check_first_line(current_line, map, fd))
	{
		free_file(previous_line, fd);
		free_file(current_line, fd);
		current_line = NULL;
		 previous_line = NULL;
		return (false);
	}
	while (current_line != NULL)
	{
		previous_line = current_line;
		current_line = get_next_line(fd);
		if (!check_last_line(current_line, previous_line, map, fd))
		{
			free(previous_line);
			free(current_line);
			current_line = NULL;
			previous_line = NULL;
			return (false);
		}
		if (row_check(current_line, map) < 0)
		{
			free(previous_line);
			free(current_line);
			current_line = NULL;
			previous_line = NULL;
			return (false);
		}
	}
	free(current_line);
	current_line = NULL;
	// free(previous_line);
	// previous_line = NULL;
	return (true);
}

bool	check_first_line(char *current_line, t_map *map, int fd)
{
	if (real_len(current_line) == 0)
	{
		free_file(current_line, fd);
		
		return (false);
	}
	map->width = real_len(current_line);
	if (row_check(current_line, map) < 0)
	{
		free_file(current_line, fd);
		return (false);
	}
	return (true);
}

bool	check_last_line(char *current_line, char *previous_line, t_map *map,
		int fd)
{
	if (current_line == NULL)
	{
		if (previous_line[map->width] == '\n')
			return (false);
		while ((size_t)(*previous_line) < map->width - 1)
		{
			if (*previous_line != '1')
				return (false);
			previous_line++;
		}
		free_file(current_line, fd);
		if (map->count_c == 0 || !map->has_p || !map->has_e)
			return (false);
		return (true);
	}
	return (true);
}
