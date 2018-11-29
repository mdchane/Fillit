/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_iterate_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:17:02 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 13:59:59 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	string_iterate_i(char *s, void (*f)(unsigned int, char *))
{
	int i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f((unsigned char)i, &s[i]);
		i++;
	}
}
