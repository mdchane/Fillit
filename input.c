/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:05:45 by apaulaus          #+#    #+#             */
/*   Updated: 2018/12/05 12:54:18 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		push_node(t_read_context *context)
{
	t_list *node;

	node = list_new(NULL, 0);
	node->content = context->tet;
	if (!context->head)
		context->head = node;
	else
		list_push_back(&context->head, node);
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

void		read_line(int y, t_v2 *pivot, t_read_context *context)
{
	char	*line;
	int		read_result;
	int		x;

	read_result = get_next_line(context->fd, &line);
	if (!read_result || string_length(line) != 4)
		error(context, read_result ? line : NULL, 0);
	x = -1;
	while (++x < 4)
	{
		if (line[x] == '#')
		{
			if (context->tet->piece_count > 3)
				error(context, line, 0);
			if (context->tet->piece_count == 0)
				*pivot = v2(x, y);
			context->tet->pieces[context->tet->piece_count++] =
				sub(v2(x, y), *pivot);
		}
		else if (line[x] != '.')
			error(context, line, 0);
	}
	free(line);
}

void		read_tetromino(t_read_context *context)
{
	t_v2		pivot;
	int			y;

	if (!(context->tet = (t_tetromino *)malloc(sizeof(t_tetromino))))
		error(context, NULL, 0);
	context->tet->piece_count = 0;
	y = -1;
	while (++y < 4)
		read_line(y, &pivot, context);
	if (context->tet->piece_count != 4 || !check_tetromino(context->tet))
		error(context, NULL, 0);
	push_node(context);
}

t_list		*read_tetrominoes(char *filename)
{
	char			*line;
	int				read_result;
	t_read_context	context;

	context.tet_count = 0;
	context.head = NULL;
	if ((context.fd = open(filename, O_RDONLY)) < 0)
		error(&context, NULL, 0);
	while (1)
	{
		read_tetromino(&context);
		context.tet_count++;
		if (context.tet_count > 26)
			error(&context, NULL, 1);
		if ((read_result = get_next_line(context.fd, &line)))
		{
			if (string_length(line) != 0)
				error(&context, line, 1);
			free(line);
		}
		else
			break ;
	}
	close(context.fd);
	return (context.head);
}
