/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:02:35 by skarev            #+#    #+#             */
/*   Updated: 2018/05/04 17:02:35 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(unsigned int nb)
{
	unsigned int i;

	if (nb == 1)
		printf("%d", nb);
	i = 2;
	while (nb > 1)
	{
		if (nb % i == 0)
		{
			printf("%d", i);
			nb /= i;
			if (nb > 1)
				printf("*");
			i--;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
}