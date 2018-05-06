/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 16:14:24 by skarev            #+#    #+#             */
/*   Updated: 2018/05/06 16:14:25 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		is_dilim(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	rostring(char *str)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (is_dilim(str[i]))
			i++;
		if (str[i] && !is_dilim(str[i]))
		{
			if (w == 0)
			{
				while (str[i] && !is_dilim(str[i]))
				{
					i++;
					w++;
				}
			}
			else
			{
				while (str[i] && !is_dilim(str[i]))
				{
					write(1, &str[i], 1);
					i++;
				}
				write (1, " ", 1);
			}
		}

	}
	i = 0;
	while (is_dilim(str[i]))
		i++;
	while (w)
	{
		write(1, &str[i], 1);
		w--;
		i++;
	}
}

int		main(int ac,char **av)
{
	if (ac == 2)
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}