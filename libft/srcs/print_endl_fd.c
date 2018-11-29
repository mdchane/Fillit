/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_endl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 08:24:38 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 14:28:35 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_endl_fd(char const *s, int fd)
{
	if (!s)
		return ;
	print_string_fd(s, fd);
	print_char_fd('\n', fd);
}
