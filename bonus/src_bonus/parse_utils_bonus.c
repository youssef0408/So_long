/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:13:09 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/13 16:32:19 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	get_ennemy(t_map *map, size_t row_idx, size_t col_idx)
{
	if (map->has_m)
		return (-3);
	else
	{
		map->m_x = col_idx;
		map->m_y = row_idx;
		map->has_m = true;
	}
	return (0);
}
