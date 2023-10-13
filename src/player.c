/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:32:43 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/12 20:24:30 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_player *player, int x, int y)
{
	if (x == -1 && y == -1)
		return ;
	player->x = x;
	player->y = y;
	player->count_c = 0;
	player->prev_x = -1;
	player->prev_y = -1;
	player->count_move = 0;
}
