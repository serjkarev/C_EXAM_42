/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 14:15:17 by skarev            #+#    #+#             */
/*   Updated: 2018/05/05 14:15:17 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		ascending(int a, int b)
{
	return (a <= b);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*head;
	t_list	*tmp;

	head = lst;
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (!(*cmp)(lst->data, tmp->data))
			{
				swap(&lst->data, &tmp->data);
			}
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (head);
}

int		main(void)
{
	t_list	*lst;
	t_list	*print;

	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = 4;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = 5;
	lst->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->data = 3;
	lst->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->data = 2;
	lst->next->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->next->data = 1;
	lst->next->next->next->next->next = NULL;
	printf("%d ", lst->data);
	printf("%d ", lst->next->data);
	printf("%d ", lst->next->next->data);
	printf("%d ", lst->next->next->next->data);
	printf("%d\n", lst->next->next->next->next->data);
	print = sort_list(lst, &ascending);
	printf("%d ", print->data);
	printf("%d ", print->next->data);
	printf("%d ", print->next->next->data);
	printf("%d ", print->next->next->next->data);
	printf("%d\n", print->next->next->next->next->data);
	return (0);
}