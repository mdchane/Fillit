/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 08:22:16 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 14:33:52 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_string_fd(char const *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, string_length(s));
}
