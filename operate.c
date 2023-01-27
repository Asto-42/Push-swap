/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:28:13 by jquil             #+#    #+#             */
/*   Updated: 2023/01/27 14:51:20 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **lst, char c)
{
	t_list	*tmp;
	t_list		*x;

	if (!(*lst))
		return;
	tmp = (*lst) -> next;
	x = (*lst);
	x -> next = tmp -> next;
	*lst = tmp;
	tmp -> next = x;
}

void	ft_push(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	if (!(*lst_a))
		return;
	tmp = (*lst_a) -> next;
	(*lst_a) -> next = *lst_b;
	*lst_b = *lst_a;
	*lst_a = tmp;
}

void	ft_rotate(t_list **lst, char c)
{
	int		x;
	t_list	*tmp;

	tmp = (*lst);
	x = (*lst)->content;
	while ((*lst)->next)
	{
		(*lst) -> content = (*lst) -> next -> content;
		(*lst) = (*lst) -> next;
	}
	(*lst) -> content = x;
	(*lst) = tmp;
}

void	ft_reverse_rotate(t_list **lst, char c)
{
	int		x;
	t_list	*tmp;

	tmp = (*lst);
	x = (*lst)->content;
	while ((*lst)->next)
	{
		(*lst) -> content = (*lst) -> next -> content;
		(*lst) = (*lst) -> next;
	}
	(*lst) -> content = x;
	(*lst) = tmp;
}
/*
t_list	*ft_reverse_rotate(t_list *lst)
{
	t_list *tmp;
	int	x;

	tmp = malloc(sizeof(t_list));
	while (lst -> next)
	{
		ft_lstadd_back(&tmp, ft_init_node(lst -> content));
		lst = lst -> next;
	}
	tmp -> content = lst -> content;
	return (tmp);
}
*/
