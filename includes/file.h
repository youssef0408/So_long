/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:59:46 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/09 16:10:24 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

int		open_file(char *file_path);
void	free_file(char *str, int fd);
size_t	get_map_height(char *file_name);
char	*generate_file_name();
// char	**map_malloc(char **grid, t_map *map);
char	**map_malloc(char **grid, size_t map_size);
void	free_map(char **grid, size_t height);
#endif