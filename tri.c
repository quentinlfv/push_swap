/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:48:03 by qlefevre          #+#    #+#             */
/*   Updated: 2022/09/28 17:19:25 by qlefevre         ###   ########.fr       */
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
}

void	push_all_inb(t_list	**stack_a, t_list **stack_b)
{
	t_list *tmp;
	int	i;
	int	mediane;

	tmp = *stack_a;
	i = 0;
	mediane = ft_stacksize(*stack_a) / 2;
	ft_printstack(*stack_a);
	printf("mediane = %d", mediane);
	while (mediane > i)
	{
		if (tmp->index < mediane)
		{
			ft_pb(stack_a, stack_b);
			i++;
			printf("i = %d", i);
		}
		else
			ft_ra(stack_a);

	}
	while (ft_stacksize(*stack_a) > 3)
		ft_pb(stack_a, stack_b);
}