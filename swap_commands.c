/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:31:34 by qlefevre          #+#    #+#             */
/*   Updated: 2022/10/12 15:31:42 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **stack_a)
{
	int		index;
	t_list	*tmp;
	t_list	*save;

	index = ft_stacksize(*stack_a);
	save = NULL;
	tmp = NULL;
	if (stack_a == NULL || index < 2)
		return ;
	if (index == 2)
	{
		tmp = (*stack_a);
		*stack_a = (*stack_a)->next;
		(*stack_a)->next = tmp;
		tmp->next = NULL;
		return ;
	}
	tmp = (*stack_a);
	*stack_a = (*stack_a)->next;
	save = (*stack_a)->next;
	(*stack_a)->next = tmp;
	tmp->next = save;
}

void	ft_sb(t_list **stack_b)
{
	int		index;
	t_list	*tmp;
	t_list	*save;

	index = ft_stacksize(*stack_b);
	save = NULL;
	tmp = NULL;
	if (stack_b == NULL || index < 2)
		return ;
	if (index == 2)
	{
		tmp = (*stack_b);
		*stack_b = (*stack_b)->next;
		(*stack_b)->next = tmp;
		tmp->next = NULL;
		return ;
	}
	tmp = (*stack_b);
	*stack_b = (*stack_b)->next;
	save = (*stack_b)->next;
	(*stack_b)->next = tmp;
	tmp->next = save;
}
