/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:13:48 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 14:34:27 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(long long n)
{
	int result;

	result = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		result++;
		n = n / 10;
	}
	return (result);
}

static void	form_string(long long num, char **result, int length)
{
	while (num > 0)
	{
		(*result)[length - 1] = (num % 10) + '0';
		length--;
		num = num / 10;
	}
}

char		*int_to_string(int n)
{
	int			length;
	int			neg;
	char		*result;
	long long	num;

	num = n;
	length = 0;
	neg = 0;
	if (num < 0)
	{
		neg = 1;
		num = -num;
		length++;
	}
	length += get_length(num);
	if (!(result = string_new(length)))
		return (NULL);
	if (neg)
		result[0] = '-';
	if (num == 0)
		result[0] = '0';
	form_string(num, &result, length);
	return (result);
}
