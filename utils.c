/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:40:09 by qlefevre          #+#    #+#             */
/*   Updated: 2022/10/13 14:40:15 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_stackclear(t_list *lst)
{
	t_list	*tmp;
	t_list	*t;

	tmp = lst;
	while (tmp)
	{
		t = tmp->next;
		free(tmp);
		tmp = t;
	}
	lst = NULL;
}

long int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long int	n;

	i = 0;
	n = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	return (n * sign);
}
