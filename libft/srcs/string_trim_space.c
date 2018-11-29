/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_trim_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:18:32 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 14:26:58 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*string_trim_space(char const *s)
{
	int		i;
	int		last_letter_index;
	char	*result;

	if (!s)
		return (NULL);
	i = 0;
	last_letter_index = 0;
	while (is_space(*s))
		s++;
	while (s[i])
	{
		if (!is_space(s[i]))
			last_letter_index = i;
		i++;
	}
	if (!(result = string_new(last_letter_index + 1)))
		return (NULL);
	i = 0;
	while (i <= last_letter_index)
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}
