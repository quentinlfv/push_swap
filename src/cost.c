/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:29:40 by qlefevre          #+#    #+#             */
/*   Updated: 2022/10/12 15:29:46 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	cost_b(t_list **stack_b, t_list **stack, int pos)
{
	int	stack_size;
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
