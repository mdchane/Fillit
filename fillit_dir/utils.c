/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:33:44 by mdchane           #+#    #+#             */
/*   Updated: 2018/11/24 11:45:47 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	***take_tetriminos(char *str_file)
{
	int		i;
	int		j;
	int		k;
	int		n;
	char	tetris[4][4];

	k = 0;
	n = 0;
	while (str_file[k])
	{
		j = 0;
		while (str_file[k] != '\n' && str_file[k + 1] != '\n')
		{
			i = 0;
			while (str_file[k] != '\n')
			{
				tetris[n][i][j] == buff[k];
				i++;
			}
			i++;
		}
		j++;
	}
}
