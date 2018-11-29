/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_uppercase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:13:46 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 13:45:57 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_to_uppercase(int c)
{
	if (c >= (int)'a' && c <= (int)'z')
		return (c - 'a' + 'A');
	return (c);
}