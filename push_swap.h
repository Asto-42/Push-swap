/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:29:01 by jquil             #+#    #+#             */
/*   Updated: 2023/01/27 16:19:36 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <unistd.h>
# include <strings.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}					t_list;

t_list		*ft_setuplst(int argc, char **argv);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
int	ft_atoi(const char *nptr);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_init_node(int x);
void	ft_swap(t_list **lst, char c);
void	ft_push(t_list **lst_a, t_list **lst_b);
void	ft_rotate(t_list **lst, char c);
void	ft_printlst(t_list **lst, char *c);
void	ft_swap_a_b(t_list *lstA, t_list *lstB);
void	ft_rotate_a_b(t_list *lstA, t_list *lstB);
void	ft_reverse_rotate(t_list **lst, char c);
void	sort_lst(int argc, t_list **lst_a);
void	ft_sort_two(t_list **lst_a, t_list **lst_b);
void	ft_sort_small(t_list **lst_a, t_list **lst_b, int x);
int		check_sort(t_list *lst);

#endif
