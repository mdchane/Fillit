/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:58:53 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 13:48:03 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memory_alloc(size_t size)
{
	void	*result;
	size_t	i;

	result = malloc(size);
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)result)[i] = 0;
		i++;
	}
	return (result);
}
