/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:07:12 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/11 15:05:50 by yothmani         ###   ########.fr       */
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
int		show_command(void);

#endif
