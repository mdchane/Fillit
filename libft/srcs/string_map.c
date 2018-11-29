/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:22:05 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 14:33:39 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*string_map(char const *s, char (*f)(char))
{
	int		i;
	char	*result;

	if (!s || !f)
		return (NULL);
	result = string_new(string_length(s));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(s[i]);
		i++;
	}
	return (result);
}
