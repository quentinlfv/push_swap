/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:31:18 by qlefevre          #+#    #+#             */
/*   Updated: 2025/02/17 16:23:02 by quelefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack_a;
	last = ft_stacklast(*stack_a);
	*stack_a = (*stack_a)->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	ft_rb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack_b;
	last = ft_stacklast(*stack_b);
	*stack_b = (*stack_b)->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	ft_rra(t_list **stack_a)
{
	int			index;
	t_list		*tmp;

	tmp = NULL;
	if (*stack_a == NULL)
		return ;
	index = ft_stacksize(*stack_a);
	tmp = *stack_a;
	*stack_a = ft_stacklast(*stack_a);
	(*stack_a)->next = tmp;
	tmp = ft_stack_toindex(index - 1, *stack_a);
	tmp->next = NULL;
}

void	ft_rrb(t_list **stack_b)
{
	int		index;
	t_list	*tmp;

	tmp = NULL;
	if (*stack_b == NULL)
		return ;
	index = ft_stacksize(*stack_b);
	tmp = *stack_b;
	*stack_b = ft_stacklast(*stack_b);
	(*stack_b)->next = tmp;
	tmp = ft_stack_toindex(index - 1, *stack_b);
	tmp->next = NULL;
}
