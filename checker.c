/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quelefev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:27:28 by quelefev          #+#    #+#             */
/*   Updated: 2025/02/17 17:48:57 by quelefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "get_next_line.h"

void	my_order(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	exec_order(line, stack_a, stack_b);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(0);
		if (line != NULL)
			exec_order(line, stack_a, stack_b);
	}
	if (line)
		free(line);
}

void	exec_order(char *order, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(order, "pa\n"))
		ft_pa(stack_a, stack_b);
	if (!ft_strcmp(order, "pb\n"))
		ft_pb(stack_a, stack_b);
	if (!ft_strcmp(order, "sa\n"))
		ft_sa(stack_a);
	if (!ft_strcmp(order, "sb\n"))
		ft_sb(stack_b);
	if (!ft_strcmp(order, "ra\n"))
		ft_ra(stack_a);
	if (!ft_strcmp(order, "rb\n"))
		ft_rb(stack_b);
	if (!ft_strcmp(order, "rra\n"))
		ft_rra(stack_a);
	if (!ft_strcmp(order, "rrb\n"))
		ft_rrb(stack_b);
	if (!ft_strcmp(order, "rrr\n"))
		ft_rrr(stack_a, stack_b);
	if (!ft_strcmp(order, "rr\n"))
		ft_rr(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 1;
	stack_a = ft_stacknew(ft_atoi(av[i]));
	stack_b = NULL;
	while (++i < ac)
		ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(av[i])));
	put_index(&stack_a);
	my_order(&stack_a, &stack_b);
	if (!check_tri(&stack_a))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	ft_stackclear(stack_a);
	return (0);
}
