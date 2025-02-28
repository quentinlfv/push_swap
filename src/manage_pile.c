/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:43:48 by qlefevre          #+#    #+#             */
/*   Updated: 2022/10/05 16:09:56 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (!check_args(argc, argv))
	{
		ft_putstr("Error\n");
		return (0);
	}
	else
		push_swap(argc, argv);
	return (0);
}

void	push_swap(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 1;
	stack_a = ft_stacknew(ft_atoi(argv[i]));
	stack_b = NULL;
	while (++i < argc)
		ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(argv[i])));
	put_index(&stack_a);
	if (check_tri(&stack_a))
		return ;
	if (ft_stacksize(stack_a) == 2)
		ft_sa(&stack_a);
	else if (ft_stacksize(stack_a) == 3)
		tri_three(&stack_a);
	else
		tri_all(&stack_a, &stack_b);
	ft_stackclear(stack_a);
	ft_stackclear(stack_b);
}

void	put_pos(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
}
