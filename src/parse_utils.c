/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:10:50 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/13 16:12:27 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_exit(t_map *map, size_t row_idx, size_t col_idx)
{
	if (map->has_e)
		return (-3);
	else
	{
		map->e_x = col_idx;
		map->e_y = row_idx;
		map->has_e = true;
	}
	return (0);
}

int	get_player(t_map *map, size_t row_idx, size_t col_idx)
{
	if (map->has_p)
		return (-3);
	else
	{
		map->p_x = col_idx;
		map->p_y = row_idx;
		map->has_p = true;
	}
	return (0);
}
