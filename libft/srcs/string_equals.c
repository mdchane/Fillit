/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_equals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:32:43 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 14:31:19 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	string_equals(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	return (string_compare(s1, s2) == 0);
}
