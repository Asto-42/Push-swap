/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:12:26 by jquil             #+#    #+#             */
/*   Updated: 2023/01/27 17:28:33 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_list **lst_a, t_list **lst_b)
{
	ft_swap(lst_a, 'a');
}

void	ft_sort_small_part_two(t_list **lst_a, t_list **lst_b, int min)
{
	while ((*lst_a) -> next -> content != min)
		ft_rotate(lst_a, 'a');
	ft_rotate(lst_a, 'a');
	ft_push(lst_a, lst_b);
	if (check_sort(*lst_a) == 0)
		ft_swap(lst_a, 'a');
	ft_push(lst_b, lst_a);
}

void	ft_sort_small(t_list **lst_a, t_list **lst_b, int x)
{
	t_list	*tmp;
	int		*tab;
	int		y;
	int		min;

	y = 0;
	tab = malloc(x * sizeof(int));
	tmp = (*lst_a);
	while (tmp)
	{
		tab[y] = tmp -> content;
		y++;
		tmp = tmp -> next;
	}
	y = 0;
	while (tab[y])
	{
		if (tab[y] < min)
			min = tab[y];
		y++;
	}
	ft_sort_small_part_two(lst_a, lst_b, min);
	if (x > 3)
	{
		ft_push(lst_a, lst_b);
		ft_sort_small(lst_a, lst_b, (x - 1));
		ft_push(lst_b, lst_a);
	}
}


/*
void	ft_sort_small_part_two(t_list **lst_a, t_list **lst_b, int min)
{
	ft_printlst(lst_a, "try mid A");
	while ((*lst_a) -> next -> content != min)
		ft_rotate(lst_a, 'a');
	ft_rotate(lst_a, 'a');
	ft_push(lst_a, lst_b);
	ft_swap(lst_a, 'a');
	if (check_sort(*lst_a) == 0)
		ft_swap(lst_a, 'a');
	ft_push(lst_b, lst_a);
}

void	ft_sort_small(t_list **lst_a, t_list **lst_b, int x)
{
	t_list	*tmp;
	int		*tab;
	int		y;
	int		min;

	y = 0;
	tab = malloc(x * sizeof(int));
	tmp = (*lst_a);
	while (tmp)
	{
		tab[y] = tmp -> content;
		y++;
		tmp = tmp -> next;
	}
	y = 0;
	while (tab[y])
	{
		if (tab[y] < min)
			min = tab[y];
		y++;
	}
	ft_sort_small_part_two(lst_a, lst_b, min);
	if (x > 3)
		ft_sort_small(lst_a, lst_b, (x - 1));
}
*/
/*
void	ft_sort_three(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;
	int		*tab;
	int		y;
	int		min;

	y = 0;
	tab = malloc(3 * sizeof(int));
	tmp = (*lst_a);
	while (tmp)
	{
		tab[y] = tmp -> content;
		y++;
		tmp = tmp -> next;
	}
	y = 0;
	while (tab[y])
	{
		if (tab[y] < min)
			min = tab[y];
		y++;
	}
	while ((*lst_a) -> next -> content != min)
		ft_rotate(lst_a, 'a');
	ft_rotate(lst_a, 'a');
	ft_push(lst_a, lst_b);
	ft_swap(lst_a, 'a');
	if (check_sort(*lst_a) == 0)
		ft_swap(lst_a, 'a');
	ft_push(lst_b, lst_a);
}
*/
