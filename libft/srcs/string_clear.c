/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:04:10 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 13:58:29 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	string_clear(char *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		s[i] = 0;
		i++;
	}
}