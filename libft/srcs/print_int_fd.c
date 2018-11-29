/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 08:26:01 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 14:29:17 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_int_fd(int n, int fd)
{
	long long num;

	num = n;
	if (num < 0)
	{
		print_char_fd('-', fd);
		num = -num;
	}
	if (num >= 10)
		print_int_fd(num / 10, fd);
	print_char_fd((num % 10) + '0', fd);
}
