/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:57:24 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/18 17:20:02 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	grid_set(t_v2 pos, char c, char *grid, int size)
{
	grid[(pos.y * size) + pos.x] = c;
}

char	grid_get(t_v2 pos, char *grid, int size)
{
	return (grid[(pos.y * size) + pos.x]);
}

int		inside_grid(t_v2 pos, int size)
{
	return (pos.x >= 0 && pos.y >= 0 &&
		pos.x < size && pos.y < size);
}

int		check_place(t_tetromino *tet, t_v2 pos, char *grid, int size)
{
	return (inside_grid(add(tet->pieces[0], pos), size)
		&& inside_grid(add(tet->pieces[1], pos), size)
		&& inside_grid(add(tet->pieces[2], pos), size)
		&& inside_grid(add(tet->pieces[3], pos), size)
		&& grid_get(add(tet->pieces[0], pos), grid, size) == '.'
		&& grid_get(add(tet->pieces[1], pos), grid, size) == '.'
		&& grid_get(add(tet->pieces[2], pos), grid, size) == '.'
		&& grid_get(add(tet->pieces[3], pos), grid, size) == '.');
}
