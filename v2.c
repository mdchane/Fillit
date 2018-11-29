/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:55:57 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/18 17:18:59 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_v2	v2(int x, int y)
{
	t_v2 result;

	result.x = x;
	result.y = y;
	return (result);
}

t_v2	add(t_v2 a, t_v2 b)
{
	return (v2(a.x + b.x, a.y + b.y));
}

t_v2	sub(t_v2 a, t_v2 b)
{
	return (v2(a.x - b.x, a.y - b.y));
}

int		equal(t_v2 a, t_v2 b)
{
	return (a.x == b.x && a.y == b.y);
}

int		touch(t_v2 a, t_v2 b)
{
	if (a.y == b.y && abs(a.x - b.x) == 1)
		return (1);
	if (a.x == b.x && abs(a.y - b.y) == 1)
		return (1);
	return (0);
}
