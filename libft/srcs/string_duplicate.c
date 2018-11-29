/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_duplicate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:04:05 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 13:59:05 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*string_duplicate(const char *s)
{
	int		length;
	char	*result;

	length = 0;
	while (s[length])
		length++;
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	while (length >= 0)
	{
		result[length] = s[length];
		length--;
	}
	return (result);
}
