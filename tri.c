/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:48:03 by qlefevre          #+#    #+#             */
/*   Updated: 2022/10/05 16:17:49 by qlefevre         ###   ########.fr       */
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
	t_list *tmp;
	t_list *save_pos;

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
	do_commands(stack_a, stack_b, &save_pos);
}


void	do_commands(t_list **stack_a, t_list **stack_b, t_list **move)
{
	if ((*move)->cost_a > 0 && (*move)->cost_b > 0)
	{
		while ((*move)->cost_a != 0 && (*move)->cost_b != 0)
		{
			ft_rrr(stack_a, stack_b);
			(*move)->cost_a += 1;
			(*move)->cost_b += 1;
			printf("rrr\n");
		}
	}
	else if ((*move)->cost_a < 0 && (*move)->cost_b < 0)
	{
		while ((*move)->cost_a != 0 && (*move)->cost_b != 0)
		{
			ft_rr(stack_a, stack_b);
			(*move)->cost_a -= 1;
			(*move)->cost_b -= 1;
			printf("rr\n");
		}
	}
	if ((*move)->cost_a > 0)
	{
		while ((*move)->cost_a != 0)
		{
			ft_ra(stack_a);
			(*move)->cost_a -= 1;
			printf("ra\n");
		}
	}
	else if ((*move)->cost_a < 0)
	{
		while ((*move)->cost_a != 0)
		{
			ft_rra(stack_a);
			(*move)->cost_a += 1;
			printf("rra\n");
		}
	}
	if ((*move)->cost_b > 0)
        {
                while ((*move)->cost_b != 0)
                {
                        ft_rb(stack_b);
                        (*move)->cost_b -= 1;
			printf("rb\n");
                }
        }
        else if ((*move)->cost_b < 0)
        {
                while ((*move)->cost_b != 0)
                {
                        ft_rrb(stack_b);
                        (*move)->cost_b += 1;
			printf("rrb\n");
                }
        }
	ft_pa(stack_a, stack_b);
	(*move)->target_pos = 0;
	(*move)->nbr_move = 0;
	printf("pa\n");
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
			printf("pb\n");
			i++;
		}
		else
		{
			ft_ra(stack_a);
			printf("ra\n");
		}
			
	}
	while (ft_stacksize(*stack_a) > 3)
	{
		ft_pb(stack_a, stack_b);
		printf("pb\b");
	}
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

void	pivot_stack_a(t_list **stack)
{
	if ((*stack)->index == 1)
		return;
	if ((*stack)->index > (ft_stacksize(*stack) / 2) + 1)
	{
		while ((*stack)->index != 1)
		{
			ft_ra(stack);
			printf("ra\n");
		}
	}
	else
		while ((*stack)->index != 1)
		{
			ft_rra(stack);
			printf("rra\n");
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
        if (stack_size - pos > mediane)
                (*stack)->cost_b = stack_size - (stack_size - pos);
        else
                (*stack)->cost_b = (stack_size - pos) * (-1);
}

