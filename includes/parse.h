/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:05:00 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/13 03:22:58 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

int		row_check(char *str, t_map *map);
int		col_check(char *str, t_map *map, size_t row_idx, size_t col_idx);
bool	parse_file(t_map *map, int fd);
bool	check_first_line(char *current_line, t_map *map, int fd);
bool	check_last_line(char *current_line, char *previous_line, t_map *map,
			int fd);

#endif