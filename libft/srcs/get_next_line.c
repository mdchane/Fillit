/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 08:12:49 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/16 15:44:18 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **l)
{
	static char	*ls[MAX_FD];
	char		b[BUFF_SIZE + 1];
	int			rs;
	char		*temp;
	char		*line_break;

	if (fd < 0 || !l || fd >= MAX_FD || (!ls[fd] && !(ls[fd] = string_new(1))))
		return (-1);
	while (!string_find_char(ls[fd], '\n') && (rs = read(fd, b, BUFF_SIZE)) > 0)
	{
		b[rs] = '\0';
		temp = ls[fd];
		ls[fd] = string_join(ls[fd], b);
		string_delete(&temp);
	}
	if (rs == -1 || !*(temp = ls[fd]))
		return (rs == -1 ? -1 : 0);
	if ((line_break = string_find_char(ls[fd], '\n')))
		*l = string_sub(ls[fd], 0, line_break - ls[fd]);
	else
		*l = string_duplicate(ls[fd]);
	ls[fd] = string_sub(ls[fd], string_length(*l) + (line_break > 0),
		string_length(ls[fd]) - (string_length(*l) + (line_break > 0)));
	string_delete(&temp);
	return (ls[fd] || string_length(*l));
}
