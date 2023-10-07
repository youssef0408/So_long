/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:07:12 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/06 18:23:21 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_player
{
	
	int	x;
	int	y;
	int	prev_x;
	int	prev_y;
	int	count_c;
	int	count_move;
}		t_player;



void	init_player(t_player *player, int x, int y);

void	move(t_player *player, int input);
// void	move_auto(t_player *player, t_map *map, int input);
void	move_up(t_player *player);
void	move_down(t_player *player);
void	move_left(t_player *player);
void	move_right(t_player *player);
// bool	can_move(t_player *player, t_map *map, int input);
// bool	can_exit(t_player *player, t_map *map, int input);
#endif
