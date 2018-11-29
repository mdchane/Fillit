/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_equals_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:36:06 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 14:35:05 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	string_equals_n(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	return (string_compare_n(s1, s2, n) == 0);
}
