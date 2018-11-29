/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:22:46 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 13:59:28 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*string_find(const char *haystack, const char *needle)
{
	int i;
	int j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0')
		{
			if (haystack[i + j] == '\0')
				return (0);
			if (haystack[i + j] != needle[j])
			{
				break ;
			}
			j++;
		}
		if (j > 0 && needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
