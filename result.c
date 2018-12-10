/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:03:44 by apaulaus          #+#    #+#             */
/*   Updated: 2018/12/05 08:18:07 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(t_read_context *context, char *line, int tet_in_list)
{
	print_string("error\n");
	if (context->fd > -1)
		close(context->fd);
	else
		exit(0);
	if (context->head)
		list_delete(&(context->head), &free_tet);
	if (context->tet && !tet_in_list)
		free_tet(context->tet, 0);
	if (line)
		string_delete(&line);
	exit(0);
}

void	print_result(char *grid, int size)
{
	int y;
	int x;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			print_char(grid[y * size + x]);
		}
		print_char('\n');
	}
}
