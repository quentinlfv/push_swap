/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:48:03 by qlefevre          #+#    #+#             */
/*   Updated: 2022/10/10 17:43:53 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_three(t_list **stack_a)
{
	if (((*stack_a)->index > (*stack_a)->next->index)
		&& (*stack_a)->index > (*stack_a)->next->next->index)
	{
		ft_ra(stack_a);
		ft_putstr("ra\n");
	}
	else if (((*stack_a)->next->index > (*stack_a)->index)
		&& (*stack_a)->next->index > (*stack_a)->next->next->index)
	{
		ft_rra(stack_a);
		ft_putstr("rra\n");
	}
	if ((*stack_a)->index > (*stack_a)->next->index)
	{
		ft_sa(stack_a);
		ft_putstr("sa\n");
	}
}

void	tri_all(t_list **stack_a, t_list **stack_b)
{
	push_all_inb(stack_a, stack_b);
	tri_three(stack_a);
	while ((*stack_b) != NULL)
	{
		put_pos(stack_a);
		put_pos(stack_b);
		put_target_pos(stack_a, stack_b);
		push_in_a(stack_a, stack_b);
	}
	pivot_stack_a(stack_a);
}

void	push_in_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*save_pos;

	tmp = *stack_b;
	while (tmp != NULL)
	{
		cost_a(stack_a, &tmp, tmp->target_pos);
		cost_b(stack_b, &tmp, tmp->pos);
		tmp->nbr_move = (abs(tmp->cost_a) + abs(tmp->cost_b));
		tmp = tmp->next;
	}
	save_pos = *stack_b;
	tmp = *stack_b;
	while (tmp != NULL)
	{
		if (save_pos->nbr_move > tmp->nbr_move)
			save_pos = tmp;
		tmp = tmp->next;
	}
	rotate_both(stack_a, stack_b, &save_pos);
	rotate_stack_a(stack_a, &save_pos);
	rotate_stack_b(stack_a, stack_b, &save_pos);
}
