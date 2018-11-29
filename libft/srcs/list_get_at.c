/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_get_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:04:19 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 13:47:22 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*list_get_at(t_list *lst, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (lst && i < n)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
