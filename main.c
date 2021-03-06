/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:49:01 by apaulaus          #+#    #+#             */
/*   Updated: 2018/12/03 11:38:53 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		abs(int num)
{
	return (num > 0 ? num : -num);
}

void	free_tet(void *tet, size_t size)
{
	(void)size;
	free(tet);
}

int		main(int argc, char **argv)
{
	t_list	*head;
	char	*grid;
	int		size;

	if (argc != 2)
	{
		print_string("usage: fillit input_file\n");
		return (0);
	}
	head = read_tetrominoes(argv[1]);
	grid = NULL;
	size = 2;
	run_algorithm(head, &grid, &size);
	print_result(grid, size);
	list_delete(&head, &free_tet);
	free(grid);
	return (0);
}
