/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:54:41 by skarev            #+#    #+#             */
/*   Updated: 2018/05/02 12:54:42 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int		ft_array_size(char *str)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (ft_is_space(str[i]))
			i++;
		else
		{
			len++;
			while (str[i] && !ft_is_space(str[i]))
				i++;
		}
	}
	return (len);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**arr;
	int		arr_size;
	int		word_size;
	int		p;

	p = 0;
	i = 0;
	j = 0;
	word_size = 0;
	if (!(arr = (char**)malloc(sizeof(char*) * (ft_array_size(str) + 1))))
		return (NULL);
	while (str[i] && j < ft_array_size(str))
	{
		while (str[i] && ft_is_space(str[i]))
			i++;
		while (str[i] && !ft_is_space(str[i]))
		{
			word_size++;
			i++;
		}
		if (!(arr[j] = (char*)malloc(sizeof(char) * (word_size + 1))))
			return (NULL);
		k = 0;
		while (word_size)
		{
			arr[j][k] = str[i - word_size];
			k++;
			word_size--;
		}
		arr[j][k] = '\0';
		j++;
	}
	while (p < ft_array_size(str))
	{
		printf("%s\n", arr[p]);
		p++;
	}
	return (arr);
}

int		main(int ac, char **av)
{
	ft_split(av[1]);
	return (0);
}