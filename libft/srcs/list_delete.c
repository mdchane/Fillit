/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:42:10 by apaulaus          #+#    #+#             */
/*   Updated: 2018/12/05 08:05:40 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	list_delete(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !del || !*alst)
		return ;
	if ((*alst)->next)
		list_delete(&(*alst)->next, del);
	list_delete_one(alst, del);
}
