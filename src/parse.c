/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:04:34 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/01 01:12:24 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	row_check(char *str, t_map *mat)
{
	size_t	col_idx;
	int		result;

	col_idx = 0;
	if (!str)
		return (-1);
	if (mat->width != real_len(str))
		return (-2);
	if (str[0] != '1' || str[mat->width - 1] != '1')
		return (-8);
	while (str[col_idx] && col_idx < mat->width - 1)
	{
		result = col_check(str, mat, mat->height, col_idx);
		if (result < 0)
			return (result);
		col_idx++;
	}
	populate_row(str, mat->height, mat);
	mat->height = mat->height + 1;
	return (0);
}

int	col_check(char *str, t_map *mat, size_t row_idx, size_t col_idx)
{
	if (mat->height == 0 && str[col_idx] != '1')
		return (-9);
	else if (str[col_idx] == 'E')
	{
		if (mat->has_e)
			return (-3);
		else
		{
			mat->e_x = col_idx;
			mat->e_y = row_idx;
			mat->has_e = true;
		}
	}
	else if (str[col_idx] == 'P')
	{
		if (mat->has_p)
			return (-4);
		else
		{
			mat->p_x = col_idx;
			mat->p_y = row_idx;
			mat->has_p = true;
		}
	}
	else if (str[col_idx] == 'M')
	{
		mat->m_x = col_idx;
		mat->m_y = row_idx;
	}
	else if (str[col_idx] == 'C')
		mat->count_c = mat->count_c + 1;
	else if (str[col_idx] != '1' && str[col_idx] != 'M' && str[col_idx] != '0'
			&& str[col_idx] != '\n')
		return (-5);
	return (0);
}

bool	parse_file(t_map *mat, int fd)
{
	char	*current_line;
	char	*previous_line;

	current_line = get_next_line(fd);
	if (!check_first_line(current_line, mat, fd))
		return (false);
	while (current_line != NULL)
	{
		previous_line = current_line;
		current_line = get_next_line(fd);
		if (!check_last_line(current_line, previous_line, mat, fd))
			return (false);
		if (row_check(current_line, mat) < 0)
		{
			free_file(current_line, fd);
			return (false);
		}
	}
	return (true);
}

bool	check_first_line(char *current_line, t_map *mat, int fd)
{
	if (real_len(current_line) == 0)
	{
		free_file(current_line, fd);
		return (false);
	}
	mat->width = real_len(current_line);
	if (row_check(current_line, mat) < 0)
	{
		free_file(current_line, fd);
		return (false);
	}
	return (true);
}

bool	check_last_line(char *current_line, char *previous_line, t_map *mat,
		int fd)
{
	if (current_line == NULL)
	{
		if (previous_line[mat->width] == '\n')
			return (false);
		while ((size_t)(*previous_line) < mat->width - 1)
		{
			if (*previous_line != '1')
				return (false);
			previous_line++;
		}
		free_file(current_line, fd);
		if (mat->count_c == 0 || !mat->has_p || !mat->has_e)
			return (false);
		return (true);
	}
	return (true);
}
