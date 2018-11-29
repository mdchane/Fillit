/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_cat_bound.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:19:25 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 13:58:18 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	string_cat_bound(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t result;

	i = 0;
	while (dst[i] != '\0')
		i++;
	result = 0;
	while (src[result] != '\0')
		result++;
	if (dstsize <= i)
		result += dstsize;
	else
		result += i;
	j = 0;
	while (i + j + 1 < dstsize && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (result);
}
