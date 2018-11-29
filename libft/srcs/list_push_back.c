/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:36:50 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 13:47:52 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	list_push_back(t_list **alst, t_list *new)
{
	t_list *current;

	if (!alst)
		return ;
	current = (*alst);
	if (!current)
		return ;
	while (current->next)
		current = current->next;
	current->next = new;
}
