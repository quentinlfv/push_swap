/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_tri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:30:34 by qlefevre          #+#    #+#             */
/*   Updated: 2025/02/17 16:48:29 by quelefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(t_list **stack_a)
{
	int	index;
	int	save;

	index = 1;
	save = find_max_value(stack_a);
	allocate_index(stack_a, save, index);
}

int	find_max_value(t_list **stack_a)
{
	t_list	*tmp;
	int		max_value;

	tmp = *stack_a;
	max_value = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content > max_value)
			max_value = tmp->content;
		tmp = tmp->next;
	}
	return (max_value);
}

void	allocate_index(t_list **stack_a, int save, int index)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (index <= ft_stacksize(*stack_a))
	{
		tmp = *stack_a;
		while (tmp != NULL)
		{
			if (tmp->index == 0 && tmp->content < save)
					save = tmp->content;
			tmp = tmp->next;
		}
		tmp = *stack_a;
		while (tmp != NULL)
		{
			if (tmp->content == save)
			{
				tmp->index = index;
				index++;
			}
			tmp = tmp->next;
		}
		save = find_max_value(stack_a);
	}
}

void	put_target_pos(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		tp_index;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_b != NULL)
	{
		tmp_a = *stack_a;
		tp_index = find_tp_index(tmp_a, tmp_b, 0);
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

int	find_tp_index(t_list *tmp_a, t_list *tmp_b, int tp_index)
{
	while (tmp_a != NULL)
	{
		if (tp_index == 0)
		{
			tmp_b->target_pos = tmp_a->pos;
			tp_index = tmp_a->index;
		}
		if ((tmp_a->index > tmp_b->index) && ((tp_index - tmp_b->index)
				> (tmp_a->index - tmp_b->index)
				|| (tp_index - tmp_b->index) < 0))
		{
			tmp_b->target_pos = tmp_a->pos;
			tp_index = tmp_a->index;
		}
		tmp_a = tmp_a->next;
	}
	return (tp_index);
}
