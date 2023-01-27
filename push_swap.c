/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:09:19 by jquil             #+#    #+#             */
/*   Updated: 2023/01/26 14:35:37 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*ft_init_node(int x)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	lst -> content = x;
	return (lst);
}

t_list	*ft_setuplst(int argc, char **argv)
{
	t_list	*lst;
	int		*tab;
	int			x;

	x = 0;
	tab = malloc ((argc - 1) * sizeof(int));
	while (argv[x + 1])
	{
		tab[x] = ft_atoi(argv[x + 1]);
		x++;
	}
	x = 0;
	lst = ft_init_node(tab[0]);
	while (tab[++x])
		ft_lstadd_back(&lst, ft_init_node(tab[x]));
	return (lst);
}
void	ft_printlst(t_list **lst, char *c)
{
	t_list	*tmp;

	if (!lst)
		printf("%s : VIDE\n", c);
	tmp = *(lst);
	while (tmp)
	{
		printf("lst %s: %i\n",c , tmp -> content);
		tmp = tmp -> next;
	}
	printf("\n");
}
int	main(int argc, char **argv)
{
	t_list	*lst_a;
	int			x;
	t_list	*tmp;

	x = 0;
	lst_a = ft_setuplst(argc, argv);
	tmp = lst_a;
	sort_lst(argc, &lst_a);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	t_list	*lstA;
	t_list	*lstB;
	int			x;
	t_list	*tmp;

	x = 0;
	lstA = ft_setuplst(argc, argv);
	tmp = lstA;
	lstA = ft_swap(lstA, 'a');
	lstA = ft_rotate(lstA, 'a');
	ft_printlst(lstA, "mid A");
	lstA = ft_reverse_rotate(lstA);
	ft_printlst(lstA, "init A");
	ft_printlst(lstB, "init B");
	ft_push(&lstA, &lstB);
	ft_printlst(lstA, "fin A");
	ft_printlst(lstB, "fin B");
	return (0);
}
*/
