/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:05:45 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/27 10:56:40 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		push_node(t_list **head, t_tetromino *tet)
{
	t_list *node;

	node = list_new(NULL, 0);
	node->content = tet;
	if (!*head)
		*head = node;
	else
		list_push_back(head, node);
}

int			check_tetromino(t_tetromino *tet)
{
	int max_touch;
	int i;
	int j;
	int touch_count;

	max_touch = 0;
	i = -1;
	while (++i < 4)
	{
		touch_count = 0;
		j = -1;
		while (++j < 4)
		{
			if (i != j)
				touch_count += touch(tet->pieces[i], tet->pieces[j]);
		}
		if (touch_count == 0)
			return (0);
		if (touch_count > max_touch)
			max_touch = touch_count;
	}
	return (max_touch > 1);
}

void		read_line(int fd, int y, t_v2 *pivot, t_tetromino *tet)
{
	char	*line;
	int		read_result;
	int		x;

	read_result = get_next_line(fd, &line);
	if (!read_result || string_length(line) != 4)
		error();
	x = -1;
	while (++x < 4)
	{
		if (line[x] == '#')
		{
			if (tet->piece_count > 3)
				error();
			if (tet->piece_count == 0)
				*pivot = v2(x, y);
			tet->pieces[tet->piece_count++] = sub(v2(x, y), *pivot);
		}
		else if (line[x] != '.')
			error();
	}
	free(line);
}

t_tetromino	*read_tetromino(int fd)
{
	t_tetromino	*tet;
	t_v2		pivot;
	int			y;

	tet = (t_tetromino *)malloc(sizeof(t_tetromino));
	tet->piece_count = 0;
	y = -1;
	while (++y < 4)
	{
		read_line(fd, y, &pivot, tet);
	}
	if (tet->piece_count != 4 || !check_tetromino(tet))
		error();
	return (tet);
}

t_list		*read_tetrominoes(char *filename)
{
	int			fd;
	t_list		*head;
	char		*line;
	int			read_result;
	t_tetromino	*tet;

	head = NULL;
	fd = open(filename, O_RDONLY);
	while (1)
	{
		tet = read_tetromino(fd);
		push_node(&head, tet);
		if ((read_result = get_next_line(fd, &line)))
		{
			if (string_length(line) != 0)
			{
				free(line);
				error();
			}
		}
		else
			break ;
	}
	close(fd);
	return (head);
}
