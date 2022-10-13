/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:28:40 by qlefevre          #+#    #+#             */
/*   Updated: 2022/10/13 14:28:12 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_both(t_list **stack_a, t_list **stack_b, t_list **move)
{
	if ((*move)->cost_a > 0 && (*move)->cost_b > 0)
	{
		while ((*move)->cost_a != 0 && (*move)->cost_b != 0)
		{
			ft_rr(stack_a, stack_b);
			(*move)->cost_a = (*move)->cost_a - 1;
			(*move)->cost_b = (*move)->cost_b - 1;
			ft_putstr("rr\n");
		}
	}
	else if ((*move)->cost_a < 0 && (*move)->cost_b < 0)
	{
		while ((*move)->cost_a != 0 && (*move)->cost_b != 0)
		{
			ft_rrr(stack_a, stack_b);
			(*move)->cost_a = (*move)->cost_a + 1;
			(*move)->cost_b = (*move)->cost_b + 1;
			ft_putstr("rrr\n");
		}
	}
}

void	rotate_stack_a(t_list **stack_a, t_list **move)
{
	if ((*move)->cost_a > 0)
	{
		while ((*move)->cost_a != 0)
		{
			ft_ra(stack_a);
			(*move)->cost_a -= 1;
			ft_putstr("ra\n");
		}
	}
	else if ((*move)->cost_a < 0)
	{
		while ((*move)->cost_a != 0)
		{
			ft_rra(stack_a);
			(*move)->cost_a += 1;
			ft_putstr("rra\n");
		}
	}
}

void	rotate_stack_b(t_list	**stack_a, t_list **stack_b, t_list **move)
{
	if ((*move)->cost_b > 0)
	{
		while ((*move)->cost_b != 0)
		{
			ft_rb(stack_b);
			(*move)->cost_b -= 1;
			ft_putstr("rb\n");
		}
	}
	else if ((*move)->cost_b < 0)
	{
		while ((*move)->cost_b != 0)
		{
			ft_rrb(stack_b);
			(*move)->cost_b += 1;
			ft_putstr("rrb\n");
		}
	}
	ft_pa(stack_a, stack_b);
	(*move)->target_pos = 0;
	(*move)->nbr_move = 0;
	ft_putstr("pa\n");
}

void	pivot_stack_a(t_list **stack)
{
	if ((*stack)->index == 1)
		return ;
	if ((*stack)->index > (ft_stacksize(*stack) / 2) + 1)
	{
		while ((*stack)->index != 1)
		{
			ft_ra(stack);
			ft_putstr("ra\n");
		}
	}
	else
	{
		while ((*stack)->index != 1)
		{
			ft_rra(stack);
			ft_putstr("rra\n");
		}
	}
}

void	push_all_inb(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	mediane;

	i = 1;
	mediane = ft_stacksize(*stack_a) / 2;
	while (mediane > i)
	{
		if ((*stack_a)->index < mediane + 1)
		{
			ft_pb(stack_a, stack_b);
			ft_putstr("pb\n");
			i++;
		}
		else
		{
			ft_ra(stack_a);
			ft_putstr("ra\n");
		}
	}
	while (ft_stacksize(*stack_a) > 3)
	{
		ft_pb(stack_a, stack_b);
		ft_putstr("pb\n");
	}
}
