/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:04:18 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/21 18:31:39 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>

void	init_game(void);
bool	parse_file(char *file_path);
void	update_game(void);
int	map_is_closed(char *file_path);

void	error_42(void);
int		map_check(int fd);
int		check_map_is_rectangular(char *file_name);

#endif
