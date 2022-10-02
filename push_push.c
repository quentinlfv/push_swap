/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:17:30 by qlefevre          #+#    #+#             */
/*   Updated: 2022/09/28 14:09:14 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	if (*stack_a == NULL)
		return;
	if ((*stack_b) == NULL)
	{
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_b)->next = NULL;
		return;
	}
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
}

void    ft_pa(t_list **stack_a, t_list **stack_b)
{
        t_list *tmp;

        if (stack_b == NULL)
                return;
        if ((*stack_a) == NULL)
        {
                *stack_a = ft_stacklast(*stack_b);
                tmp = ft_stack_toindex(ft_stacksize(*stack_b) - 2, *stack_b);
                tmp->next = NULL;
                return;
        }
        tmp = ft_stacklast(*stack_a);
        tmp->next = ft_stacklast(*stack_b);
        tmp = ft_stack_toindex(ft_stacksize(*stack_b) - 2, *stack_b);
        tmp->next = NULL;
	if (*stack_b == ft_stacklast(*stack_a))
		(*stack_b) = NULL;
}

void	ft_sa(t_list **stack_a)
{
	int	index;
	t_list	*tmp;
	t_list	*save;

	index = ft_stacksize(*stack_a);
	save = NULL;
	tmp = NULL;
	if (stack_a == NULL || index < 2)
		return;
	if (index == 2)
	{
		tmp = (*stack_a);
		*stack_a = (*stack_a)->next;
		(*stack_a)->next = tmp;
		tmp->next = NULL;
		return;
	}
	tmp = (*stack_a);
	*stack_a = (*stack_a)->next;
	save = (*stack_a)->next;
	(*stack_a)->next = tmp;
	tmp->next = save;
}

void    ft_sb(t_list **stack_b)
{
        int     index;
        t_list  *tmp;
        t_list  *save;

        index = ft_stacksize(*stack_b);
        save = NULL;
        tmp = NULL;
        if (stack_b == NULL || index < 2)
                return;
        if (index == 2)
        {
                tmp = (*stack_b);
                *stack_b = (*stack_b)->next;
                (*stack_b)->next = tmp;
                tmp->next = NULL;
                return;
        }
        tmp = ft_stack_toindex(index - 2, *stack_b);
        save = ft_stack_toindex(index - 1, *stack_b);
        save->next = tmp;
        tmp->next = NULL;
        tmp = ft_stack_toindex(index - 3, *stack_b);
        tmp->next = save;
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

void	ft_ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack_a;
	last = ft_stacklast(*stack_a);
	*stack_a = (*stack_a)->next;
	last->next = tmp;
	tmp->next = NULL;
}

void    ft_rb(t_list **stack_b)
{
        t_list  *tmp;
        t_list  *last;

        tmp = *stack_b;
        last = ft_stacklast(*stack_b);
        *stack_b = (*stack_b)->next;
        last->next = tmp;
        tmp->next = NULL;
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}

void	ft_rra(t_list **stack_a)
{
	int	index;
	t_list	*tmp;

	tmp = NULL;
	if (*stack_a == NULL)
		return;
	index = ft_stacksize(*stack_a);
	tmp = *stack_a;
	*stack_a = ft_stacklast(*stack_a);
	(*stack_a)->next = tmp;
	tmp = ft_stack_toindex(index - 1, *stack_a);
	tmp->next = NULL;
}

void    ft_rrb(t_list **stack_b)
{
        int     index;
        t_list  *tmp;

        tmp = NULL;
        if (*stack_b == NULL)
                return;
        index = ft_stacksize(*stack_b);
        tmp = *stack_b;
        *stack_b = ft_stacklast(*stack_b);
        (*stack_b)->next = tmp;
        tmp = ft_stack_toindex(index - 1, *stack_b);
        tmp->next = NULL;
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}

