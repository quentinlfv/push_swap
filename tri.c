/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:48:03 by qlefevre          #+#    #+#             */
/*   Updated: 2022/10/03 19:43:29 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_three(t_list **stack_a)
{
	if 	((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->index > (*stack_a)->next->next->index)
		ft_ra(stack_a);
	else if ((*stack_a)->next->index > (*stack_a)->index && (*stack_a)->next->index > (*stack_a)->next->next->index)
		ft_rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		ft_sa(stack_a);
}

void	tri_all(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	//push_all_inb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	//tri_three(stack_a);
	put_pos(stack_a);
	put_pos(stack_b);
	put_target_pos(stack_a, stack_b);
	tmp = *stack_b;
	while (tmp != NULL)
	{
		cost_a(stack_a, &tmp, tmp->target_pos);
		cost_b(stack_b, &tmp, tmp->pos);
		tmp = tmp->next;
	}
}

void	push_all_inb(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	int	i;
	int	mediane;

	i = 1;
	mediane = ft_stacksize(*stack_a) / 2;
	printf("mediane = %d\n", mediane);
	while (mediane > i)
	{
		tmp = *stack_a;
		if (tmp->index < mediane)
		{
			ft_pb(stack_a, stack_b);
			i++;
		}
		else
			ft_ra(stack_a);
	}
	while (ft_stacksize(*stack_a) > 3)
		ft_pb(stack_a, stack_b);
}

void	put_target_pos(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp_a;
	t_list *tmp_b;
	int	tp_index;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	tp_index = 0;

	while (tmp_b != NULL)
	{
		tmp_a = *stack_a;
		tp_index = 0;
		while (tmp_a != NULL)
		{
			if (tp_index == 0)
			{
				tmp_b->target_pos = tmp_a->pos;
				tp_index = tmp_a->index;
			}
			if (tmp_a->index > tmp_b->index && (tp_index - tmp_b->index) > (tmp_a->index - tmp_b->index) 
					|| (tp_index - tmp_b->index) < 0)
			{
				printf("tmp_a->index : %d\n", tmp_a->index);
				tmp_b->target_pos = tmp_a->pos;
				tp_index = tmp_a->index;
			}
			tmp_a = tmp_a->next;
		}
		if (tmp_b->index > tp_index)
		{
			tmp_a = *stack_a;
			while (tmp_a != NULL)
			{
				if (tmp_a->index < tp_index)
				{
					tmp_b->target_pos = tmp_a->pos;
					tp_index = tmp_a->index;
				}
				tmp_a = tmp_a->next;
			}
		}
		tmp_b = tmp_b->next;
	}
}

void	cost_a(t_list **stack_a, t_list **stack_b, int pos)
{
	int	stack_size;
	int	mediane;

	stack_size = ft_stacksize(*stack_a);
	if (stack_size % 1 == 1)
		mediane = stack_size / 2 + 1;
	else 
		mediane = stack_size / 2;
	printf("stack_size = %d | pos : %d\n", stack_size, pos);
	if (stack_size - pos > mediane)
		(*stack_b)->cost_a = (stack_size - (stack_size - pos));
	else 
		(*stack_b)->cost_a = (stack_size - pos) * (-1);
}

void    cost_b(t_list **stack_b, t_list **stack, int pos)
{
        int     stack_size;
	int	mediane;

        stack_size = ft_stacksize(*stack_b);
	if (stack_size % 1 == 1)
		mediane = stack_size / 2 + 1;
	else
		mediane = stack_size / 2;
	printf("mediane = %d | stacksize = %d\n", mediane, stack_size);
        if (stack_size - pos > mediane)
                (*stack)->cost_b = stack_size - (stack_size - pos);
        else
                (*stack)->cost_b = (stack_size - pos) * (-1);
}

