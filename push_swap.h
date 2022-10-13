/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:36:12 by qlefevre          #+#    #+#             */
/*   Updated: 2022/10/13 14:42:22 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				nbr_move;
	struct s_list	*next;
}t_list;

/* utils.c */
void		ft_putstr(char *s);
void		ft_stackclear(t_list *lst);
long int	ft_atoi(const char *nptr);

/* fonctions.c */

int			abs(int a);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *string1, const char *string2);
char		*ft_strdup(const char *s);

/* list_fonctions.c */

t_list		*ft_stacknew(int content);
t_list		*ft_stacklast(t_list *lst);
t_list		*ft_stack_toindex(int index, t_list *stack);
int			ft_stacksize(t_list *lst);
void		ft_stackadd_back(t_list **lst, t_list *new);

/* check_error.c */

int			check_args(int argc, char **argv);
int			check_double(int argc, char **argv);
int			check_isint(int argc, char **argv);
int			check_tri(t_list **stack_a);

/* manage_pile.c */

void		push_swap(int argc, char **argv);
void		put_pos(t_list **stack);

/* help_tri.c */

void		put_index(t_list **stack_a);
int			find_max_value(t_list **stack_a);
void		allocate_index(t_list **stack_a, int save, int index);
void		put_target_pos(t_list **stack_a, t_list **stack_b);
int			find_tp_index(t_list *tmp_a, t_list *tmp_b, int tp_index);

/* cost.c */

void		cost_a(t_list **stack_a, t_list **stack_b, int pos);
void		cost_b(t_list **stack_b, t_list **stack, int pos);

/* tri.c */

void		tri_three(t_list **stack_a);
void		tri_all(t_list **stack_a, t_list **stack_b);
void		push_in_a(t_list **stack_a, t_list **stack_b);

/* actions.c */

void		rotate_both(t_list **stack_a, t_list **stack_b, t_list **move);
void		rotate_stack_a(t_list **stack_a, t_list **move);
void		rotate_stack_b(t_list **stack_a, t_list **stack_b, t_list **move);
void		push_all_inb(t_list	**stack_a, t_list **stack_b);
void		pivot_stack_a(t_list **stack);

/* commands */

void		ft_pb(t_list **stack_a, t_list **stack_b);
void		ft_pa(t_list **stack_a, t_list **stack_b);
void		ft_sa(t_list **stack_a);
void		ft_sb(t_list **stack_b);
void		ft_ss(t_list **stack_a, t_list **stack_b);
void		ft_ra(t_list **stack_a);
void		ft_rb(t_list **stack_b);
void		ft_rr(t_list **stack_a, t_list **stack_b);
void		ft_rra(t_list **stack_a);
void		ft_rrb(t_list **stack_b);
void		ft_rrr(t_list **stack_a, t_list **stack_b);

#endif
