/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:58:57 by skarev            #+#    #+#             */
/*   Updated: 2018/05/01 13:58:58 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_print(char *str, int i)
{
	while (str[i] != ' ' && str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_rew_wstr(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	len--;
	while (str[len])
	{
		while (str[len] != ' ' && str[len])	
			len--;
		i = len;
		ft_print(str, ++i);
		if (len == -1)
			break ;
		else
			write(1, " ", 1);
		len--;
	}
}
int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_rew_wstr(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}