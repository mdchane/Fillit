/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:25:38 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 14:00:52 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	string_to_int(const char *str)
{
	int			i;
	long long	result;
	long long	neg;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || '9' < str[i])
			return (result * neg);
		else
			result = (result * 10) + (long long)(str[i] - '0');
		i++;
	}
	return (result * neg);
}
