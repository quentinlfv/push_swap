#include "push_swap.h"
#include "get_next_line.h"

void	print_order(char **order)
{
	int	i = 0;
	while (order[i])
	{
		printf("%s\n", order[i]);
		i++;
	}
}

void	print_stack(t_list *stack)
{
	t_list *tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}

char	**get_order(void)
{
	char	**order;
	char	*line;
	int		size;

	order = NULL;
	size = 0;
	line = get_next_line(0);
	order = add_new_order(order, line, &size);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(0);
		if (line != NULL)
			order = add_new_order(order, line, &size);
	}
	print_order(order);
	return (order);
}

char	**add_new_order(char **order, char *line, int *size)
{
	char	**new_order;
	int		i;

	i = 0;
	new_order = malloc(sizeof(char *) * (*size + 2));
	if (!new_order)
		return (NULL);
	while (i < (*size))
	{
		new_order[i] = order[i];
		i++;
	}
	new_order[i] = malloc(sizeof(char) * (ft_strlen(line)));
	if (!new_order[i])
		return (NULL);
	ft_strlcpy(new_order[i], line, ft_strlen(line));
	new_order[i + 1] = NULL;
	free(order);
	(*size)++;
	return (new_order);
}
	
void	exec_order(char **order, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (order[i])
	{
		if (ft_strcmp(order[i], "pa\n"))
			ft_pa(stack_a, stack_b);
		if (ft_strcmp(order[i], "pb\n"))
			ft_pb(stack_a, stack_b);
		if (ft_strcmp(order[i], "sa\n"))
			ft_sa(stack_a);
		if (ft_strcmp(order[i], "sb\n"))
			ft_sb(stack_b);
		if (ft_strcmp(order[i], "ra\n"))
			ft_ra(stack_a);
		if (ft_strcmp(order[i], "rb\n"))
			ft_rb(stack_b);
		if (ft_strcmp(order[i], "rra\n"))
			ft_rra(stack_a);
		if (ft_strcmp(order[i], "rrb\n"))
			ft_rrb(stack_b);
		i++;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int ac, char **av)
{
	char	**order;
	t_list *stack_a;
	t_list *stack_b;
	int	i;

	i = 1;
	stack_a = ft_stacknew(ft_atoi(av[i]));
	stack_b = NULL;
	while (++i < ac)
		ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(av[i])));
	print_stack(stack_a);
	order = get_order();
	exec_order(order, &stack_a, &stack_b);
	if (!check_tri(&stack_a))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	free_tab(order);
	ft_stackclear(stack_a);
	return (0);
}
