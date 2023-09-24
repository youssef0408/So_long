/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:08:40 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/24 17:30:44 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// up
void	init_player_position(t_player *player, t_map map)
{
	player->x = map.p_x;
	player->y = map.p_y;
}
void	move_up(t_player *player)
{
	player->y = player->y - 1;
}
void	move_down(t_player *player)
{
	player->y = player->y + 1;
}
void	move_left(t_player *player)
{
	player->x = player->x - 1;
}
void	move_right(t_player *player)
{
	player->x = player->x + 1;
}
