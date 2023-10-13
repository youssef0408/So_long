/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:59:46 by yothmani          #+#    #+#             */
/*   Updated: 2023/10/12 20:34:49 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

int		open_file(char *file_path);
void	free_file(char *str, int fd);
void	free_map(char **grid, size_t height);


#endif