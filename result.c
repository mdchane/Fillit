/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:03:44 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/29 11:48:42 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	print_string("error\n");
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
