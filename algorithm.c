/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:13:46 by apaulaus          #+#    #+#             */
/*   Updated: 2018/12/03 15:42:16 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		place_tetromino(t_list *node, int n, char *grid, int size)
{
	t_tetromino	*tet;
	int			i;
	t_v2		pos;

	tet = (t_tetromino *)node->content;
	i = -1;
	while (++i < size * size)
	{
		pos = v2(i % size, i / size);
		if (check_place(tet, pos, grid, size))
		{
			grid_set(add(tet->pieces[0], pos), 'A' + n, grid, size);
			grid_set(add(tet->pieces[1], pos), 'A' + n, grid, size);
			grid_set(add(tet->pieces[2], pos), 'A' + n, grid, size);
			grid_set(add(tet->pieces[3], pos), 'A' + n, grid, size);
			if (!node->next || place_tetromino(node->next, n + 1, grid, size))
				return (1);
			grid_set(add(tet->pieces[0], pos), '.', grid, size);
			grid_set(add(tet->pieces[1], pos), '.', grid, size);
			grid_set(add(tet->pieces[2], pos), '.', grid, size);
			grid_set(add(tet->pieces[3], pos), '.', grid, size);
		}
	}
	return (0);
}

void	run_algorithm(t_list *head, char **grid, int *size)
{
	int i;

	while (1)
	{
		if (*grid)
			free(*grid);
		if (!(*grid = (char *)malloc(sizeof(char) * (*size * *size))))
		{
			print_string("error\n");
			list_delete(&head, &free_tet);
			exit(0);
		}
		i = -1;
		while (++i < *size * *size)
			(*grid)[i] = '.';
		if (place_tetromino(head, 0, *grid, *size))
			break ;
		(*size)++;
	}
}
