/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 14:15:55 by skarev            #+#    #+#             */
/*   Updated: 2018/05/05 14:15:56 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIST_H_
# define _LIST_H_
# include <stdio.h>
# include <stdlib.h>

typedef struct  	s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

#endif
