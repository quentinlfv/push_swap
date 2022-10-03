/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:43:48 by qlefevre          #+#    #+#             */
/*   Updated: 2022/09/29 17:44:27 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_stack_a(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int	i;


	i = 1;
	stack_a = ft_stacknew(ft_atoi(argv[i]));
	stack_b = NULL;
	while (++i < argc)
		ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(argv[i])));
	if (check_tri(&stack_a))
	{
		printf("stack is tried!\n");
		return;
	}
	ft_printstack(stack_a);
	put_index(&stack_a);
	if (ft_stacksize(stack_a) == 2)
		ft_sa(&stack_a);
	else if (ft_stacksize(stack_a) == 3)
		tri_three(&stack_a);
	else
		tri_all(&stack_a, &stack_b);	
	ft_printstack(stack_a);
	printf("a\n\n");
	ft_printstack(stack_b);
	printf("b\n\n");
	ft_stackclear(stack_a);
	ft_stackclear(stack_b);
}

void	put_index(t_list **stack_a)
{
	int	index;
	int	save;
	int	min_value;
	t_list 	*tmp;

	index = 1;
	tmp = *stack_a;
	min_value = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content < min_value)
			min_value = tmp->content;
		tmp = tmp->next;
	}
	save = min_value;
	while (index <= ft_stacksize(*stack_a))
	{
		tmp = *stack_a;
		while (tmp != NULL)
		{
			if (tmp->index == 0 && tmp->content > save)
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
		save = min_value;
	}
}

int	check_tri(t_list **stack_a)
{
	t_list *tmp;
<<<<<<< HEAD
	int	save;

	tmp = *stack_a;
	save = tmp->content;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (save < tmp->content)
			return (0);
		save = tmp->content;
	}
	return (1);
}

=======

	tmp = *stack_a;
	while (tmp->next !=NULL)
	{
			if (tmp->index > tmp->next->index)
				return (0);
			tmp = tmp->next;
	}
	return (1);
}
>>>>>>> b4741fec65425e6f03db880df2ff6f08caecefbe
