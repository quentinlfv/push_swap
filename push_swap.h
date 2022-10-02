/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:36:12 by qlefevre          #+#    #+#             */
/*   Updated: 2022/09/28 14:25:27 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H_
#define _PUSH_SWAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_list
{
	int		content;
	int		index;
	struct s_list	*next;
}t_list;

int     	ft_isdigit(int c);
size_t  	ft_strlen(const char *s);
int     	ft_strcmp(const char *string1, const char *string2);
char    	*ft_strdup(const char *s);
long int        ft_atoi(const char *nptr);


t_list  *ft_stacknew(int content);
t_list  *ft_stacklast(t_list *lst);
t_list  *ft_stack_toindex(int index, t_list *stack);
int     ft_stacksize(t_list *lst);
void	ft_printstack(t_list *lst);
void    ft_stackclear(t_list *lst);
void    ft_stackadd_front(t_list **lst, t_list *new);
void    ft_stackadd_back(t_list **lst, t_list *new);


int     check_args(int argc, char **argv);
int     check_double(int argc, char **argv);
int		check_isint(int argc, char **argv);
int		check_tri(t_list **stack_a);

void	new_stack_a(int argc, char **argv);
void	put_index(t_list **stack_a);

void	tri_three(t_list **stack_a);
void	tri_all(t_list **stack_a, t_list **stack_b);
void	push_all_inb(t_list	**stack_a, t_list **stack_b);

void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);

#endif
