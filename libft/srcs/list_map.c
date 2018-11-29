/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:52:45 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 13:47:38 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*list_map(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *last;

	result = NULL;
	while (lst)
	{
		if (!result)
		{
			result = f(lst);
			last = result;
		}
		else
		{
			last->next = f(lst);
			last = last->next;
		}
		lst = lst->next;
	}
	return (result);
}
