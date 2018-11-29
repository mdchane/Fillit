/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaulaus <apaulaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:34:15 by apaulaus          #+#    #+#             */
/*   Updated: 2018/11/14 14:33:17 by apaulaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int result;
	int in_word;
	int i;

	result = 0;
	in_word = 0;
	i = 1;
	while (s[i - 1])
	{
		if (s[i] == c || s[i] == 0)
		{
			if (in_word)
				result++;
			in_word = 0;
		}
		else
			in_word = 1;
		i++;
	}
	return (result);
}

static int	clean(char **result, int word_count)
{
	int i;

	i = 0;
	while (i < word_count)
	{
		free(result[i]);
		i++;
	}
	return (0);
}

static int	split(char const *s, char c, char **result, int w)
{
	int i;
	int in_word;
	int word_start;

	i = 0;
	in_word = 0;
	while (i == 0 || s[i - 1])
	{
		if (!(s[i] == c || s[i] == 0))
		{
			if (!in_word)
				word_start = i;
			in_word = 1;
		}
		else
		{
			if (in_word)
				if (!(result[w++] = string_sub(s, word_start, i - word_start)))
					return (clean(result, w - 1));
			in_word = 0;
		}
		i++;
	}
	return (1);
}

char		**string_split(char const *s, char c)
{
	int		word_count;
	char	**result;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	if (!split(s, c, result, 0))
		return (NULL);
	result[word_count] = 0;
	return (result);
}
