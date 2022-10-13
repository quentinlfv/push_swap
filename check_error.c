/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:29:09 by qlefevre          #+#    #+#             */
/*   Updated: 2022/10/12 15:29:16 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][0] != 45 && argv[i][0] != 43)
				return (0);
		}
	}
	if (!check_double(argc, argv) || !check_isint(argc, argv))
		return (0);
	return (1);
}

int	check_isint(int argc, char **argv)
{
	int			i;
	long int	nbr;

	i = 0;
	while (++i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
	}
	return (1);
}

int	check_double(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (++i < argc)
	{
		str = ft_strdup(argv[i]);
		j = i;
		while (++j < argc)
		{
			if (!ft_strcmp(str, argv[j]))
				return (0);
		}
		free(str);
	}
	return (1);
}

int	check_tri(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
