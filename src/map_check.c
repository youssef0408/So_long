/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:46:59 by yothmani          #+#    #+#             */
/*   Updated: 2023/09/21 17:25:25 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	check_map_is_closed(char *file_path)
// {
// 	int		fd;
// 	int		rows;
// 	int		cols;
// 	char	ch;
// 	int		current_col;

// 	rows = 0;
// 	cols = 0;
// 	fd = open(file_path, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("ERROR opening file\n");
// 		return (1);
// 	}
// 	current_col = 0;
// 	int first_row = 1; // Pour suivre la première rangée
// 	int last_row = 0;  // Pour suivre la dernière rangée
// 	int first_col = 1; // Pour suivre la première colonne
// 	int last_col = 0;  // Pour suivre la dernière colonne
// 	while (read(fd, &ch, 1) == 1)
// 	{
// 		if (ch == '1')
// 		{
// 			cols++;
// 			current_col++;
// 		}
// 		else if (ch == '\n')
// 		{
// 			rows++;
// 			current_col = 0;
// 			last_row = 1; // Atteint la fin de la rangée
// 		}
// 		else
// 		{
// 			perror("Error: Invalid character in the map\n");
// 			close(fd);
// 			return (0);
// 		}
// 		if ((first_row || last_row) && ch != '1')
// 		{
// 			perror("Error: First or last row contains non-'1' characters\n");
// 			close(fd);
// 			return (0);
// 		}
// 		if ((first_col || last_col) && current_col == 1 && ch != '1')
// 		{
// 			perror("Error: First or last column contains non-'1' characters\n");
// 			close(fd);
// 			return (0);
// 		}
// 		if (current_col > 1)
// 		{
// 			first_row = 0; // La première rangée n'est plus suivie
// 			last_row = 0;  // La dernière rangée n'est plus suivie
// 		}
// 		if (rows > 1)
// 		{
// 			first_col = 0; // La première colonne n'est plus suivie
// 			last_col = 0;  // La dernière colonne n'est plus suivie
// 		}
// 	}
// 	// Fermeture du fichier
// 	close(fd);
// 	if (rows < 2 || cols == 0)
// 	{
// 		perror("Error: Map is too small to be closed\n");
// 		return (0);
// 	}
// 	return (1); // La carte est correctement fermée
// }
