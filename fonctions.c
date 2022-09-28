/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:01:42 by qlefevre          #+#    #+#             */
/*   Updated: 2022/09/21 17:13:50 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

size_t  ft_strlen(const char *s)
{
	int     i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int     ft_strcmp(const char *string1, const char *string2)
{
	unsigned int    i;

	i = 0;
	while (string1[i] == string2[i] && (string1[i] || string2[i]))
		i++;
	return (((unsigned char)string1[i]) - ((unsigned char)string2[i]));
}

char    *ft_strdup(const char *s)
{
	char            *dup;
	size_t          i;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	while (i < ft_strlen(s))
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

long int	ft_atoi(const char *nptr)
{
	int		i;
	long int	n;
	int		sign;

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
