/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:30:30 by jquil             #+#    #+#             */
/*   Updated: 2023/01/27 16:30:57 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_sort(t_list *lst)
{
	t_list	*x;
	t_list	*y;

	x = (lst);
	y = (lst) -> next;
	while (lst)
	{
		if ((x -> content) > (y -> content))
			return (0);
		else
		{
			x = y;
			lst = lst -> next;
			y = lst;
		}
	}

	return (1);
}

void	sort_lst(int argc, t_list **lst_a)
{
	t_list	**lst_b;
	t_list	*tmp;

	ft_printlst(lst_a, "try 1");

	tmp = *(lst_a);
	lst_b = malloc(sizeof(t_list**));
	argc = argc - 1;
	if (check_sort(*lst_a) == 0)
	{
		lst_a = &tmp;
		if (argc == 2)
			ft_sort_two(lst_a, lst_b);
		if (argc == 3)
			ft_sort_small(lst_a, lst_b, 3);
		if (argc = 4)
			ft_sort_small(lst_a, lst_b, 4);
		if (argc = 5)
			ft_sort_small(lst_a, lst_b, 5);
		//else
		//	ft_sort_big(lst_a, lst_b, argc);
		ft_printlst(lst_a, "try final A");
	}

	else
	{
		return;
	}
}
