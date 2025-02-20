/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fonctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:30:07 by qlefevre          #+#    #+#             */
/*   Updated: 2022/10/04 11:37:47 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_stacknew(int content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	list->index = 0;
	return (list);
}

t_list	*ft_stacklast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*ft_stack_toindex(int index, t_list *stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (stack);
	while (i < index)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

int	ft_stacksize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void	ft_stackadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_stacklast(*lst);
		tmp->next = new;
	}
}
