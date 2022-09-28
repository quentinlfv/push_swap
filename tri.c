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
	t_list	*tmp;
	int	index;
	int	i;

	tmp = *stack_a;
	index = tmp->index;
	while (tmp != NULL)
	{
		if (tmp->index > index)
			index = tmp->index;
		tmp = tmp->next;
	}
	if 
}
