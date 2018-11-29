/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:09:22 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/18 17:40:40 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*list_new(void const *content, size_t content_size)
{
	t_list *result;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	if (!content)
	{
		result->content = NULL;
		result->content_size = 0;
	}
	else
	{
		result->content = memory_alloc(content_size);
		if (!result->content)
			return (NULL);
		memory_copy(result->content, content, content_size);
		result->content_size = content_size;
	}
	result->next = NULL;
	return (result);
}
