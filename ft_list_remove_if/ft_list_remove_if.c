/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 18:15:16 by skarev            #+#    #+#             */
/*   Updated: 2018/05/04 18:15:17 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

int		cmp(int a, int b)
{
	if (a != b)
		return (1);
	return (0);
}

void	ft_list_remove_if(t_list **begin_list, int data_ref, int (*cmp)(int, int))
{
	t_list	*tmp;
	t_list	*current;

	while (*begin_list && cmp((*begin_list)->data, data_ref))
	{
		tmp = begin_list;
		begin_list = begin_list->next;
		free(tmp);
	}
	current = *begin_list;
	while (current && current->next)
	{
		if (!(cmp(current->next->data, data_ref)))
		{
			tmp = current->next;
			current->next = tmp->next;
			free(tmp);
		}
		current = current->next;
	}
}

int		main(void)
{
	int		data_ref;

	data_ref = 3;
	t_list *begin_list = NULL;
	begin_list = (t_list*)malloc(sizeof(t_list));
	begin_list->data = 1;
	begin_list->next = (t_list*)malloc(sizeof(t_list));
	begin_list->next->data = 2;
	begin_list->next->next = (t_list*)malloc(sizeof(t_list));
	begin_list->next->next->data = 3;
	begin_list->next->next->next = (t_list*)malloc(sizeof(t_list));
	begin_list->next->next->next->data = 4;
	begin_list->next->next->next->next = (t_list*)malloc(sizeof(t_list));
	begin_list->next->next->next->next->data = 5;
	begin_list->next->next->next->next->next = NULL;
	ft_list_remove_if(&begin_list, data_ref, &cmp);
	return (0);
}
