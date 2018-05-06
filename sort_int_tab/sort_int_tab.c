/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 13:47:09 by skarev            #+#    #+#             */
/*   Updated: 2018/05/05 13:47:09 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	unsigned int tmp;

	i = 1;
	if (size != 0)
	{
		while (i <= size)
		{
			if (tab[i] < tab[i - 1])
			{
				tmp = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = tmp;
				i = 0;
			}
			i++;
		}
	}
}

int 	main(void)
{
	int tab[10];
	int i;

	i = 0;
	tab[0] = 4;
	tab[1] = 5;
	tab[2] = 6;
	tab[3] = 3;
	tab[4] = 9;
	tab[5] = 2;
	tab[6] = 0;
	tab[7] = 4;
	tab[8] = 1;
	tab[9] = 7;
	sort_int_tab(tab, 9);
	while (i <= 9)
		printf("%d ", tab[i++]);
	return (0);
}