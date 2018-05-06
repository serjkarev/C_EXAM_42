/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:28:48 by skarev            #+#    #+#             */
/*   Updated: 2018/05/02 16:28:48 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		is_space(char c)
{
	if (c < 33)
		return (1);
	return (0);
}

int		count_word(char *str)
{
	unsigned int	w;

	w = 0;
	while (*str)
	{
		if (is_space(*str))
			str++;
		else
		{
			w++;
			while (*str && !is_space(*str))
				str++;
		}
	}
	return (w);
}

char	**ft_split_2(char *str)
{
	int		i;
	int 	j;
	int		k;
	int		word;
	char	**arr;
	int		p;

	i = 0;
	k = 0;
	p = 0;
	j = 0;
	if (!(arr = (char**)malloc(sizeof(char*) * (count_word(str) + 1))))
		return (NULL);
	arr[count_word(str)] = NULL;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		word = 0;
		while (str[i] && !is_space(str[i]))
		{
			i++;
			word++;
		}
		k = 0;
		if (!(arr[j] = (char*)malloc(sizeof(char) * (word + 1))))
			return (NULL);
		while (word)
		{
			arr[j][k] = str[i - word];
			word--;
			k++;
		}
		arr[j][k] = '\0';
		j++;
	}
	while (arr[p] != NULL) 
	{
		printf("%s\n", arr[p]);
		p++;
	}
	return(arr);
}
//////////////////////////////////////////////////////////////////////////////

int		main(int ac, char **av)
{
	ft_split_2(av[1]);
	return (0);
}