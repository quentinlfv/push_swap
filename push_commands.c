/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:30:57 by qlefevre          #+#    #+#             */
/*   Updated: 2022/10/12 15:31:01 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a == NULL)
		return ;
	if ((*stack_b) == NULL)
	{
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_b)->next = NULL;
		return ;
	}
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b == NULL)
		return ;
	if ((*stack_a) == NULL)
	{
		*stack_a = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_a)->next = NULL;
		return ;
	}
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_a)->next;
	(*stack_a)->next = tmp;
}
