/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdescamp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:32:53 by hdescamp          #+#    #+#             */
/*   Updated: 2024/12/16 14:28:25 by hdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

//List

typedef struct s_slist
{
	int				value;
	int				index;
	long long		result;
	int				sign;
	struct s_slist	*next;
}	t_tlist;

//Tools

t_tlist		*ft_lsttnew(int value);
t_tlist		*ft_lsttlast(t_tlist *head);
void		ft_lsttadd_front(t_tlist **stack, t_tlist *new);
void		ft_lsttadd_back(t_tlist **stack, t_tlist *new);
void		printList(t_tlist *head);
int			ft_lsttsize(t_tlist *head);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
long long	ft_atoll(const char *str);

//Utils

void		ft_error(char *msg);
void		ft_check_args(int argc, char **argv);
int			is_sorted(t_tlist **stack);
int			get_distance(t_tlist **stack, int index);
void		make_top(t_tlist **stack, int distance);
void		free_stack(t_tlist **stack);
void		ft_free(char **str);
void		ft_free_split(char **tab);

//Sort

void		radix_sort(t_tlist **stack_a, t_tlist **stack_b);
void		simple_sort(t_tlist **stack_a, t_tlist **stack_b);
void		index_stack(t_tlist **stack);
void		sort_5(t_tlist **stack_a, t_tlist **stack_b);
void		sort_three_cases(t_tlist **stack_a);
void		sort_3(t_tlist **stack_a);
void		handle_sorted_or_rotate(t_tlist **stack_a, int min, int next_min);
int			get_min(t_tlist **stack, int val);
void		reduc_sort_3(t_tlist **stack_a, int min, t_tlist *head);

//Generic Operand

int			swap(t_tlist **stack);
int			push(t_tlist **stack_to, t_tlist **stack_from);
int			rotate(t_tlist **stack);
int			reverserotate(t_tlist **stack);

//Operand

int			sa(t_tlist **stack_a);
int			sb(t_tlist **stack_b);
int			ss(t_tlist **stack_a, t_tlist **stack_b);
int			pa(t_tlist **stack_a, t_tlist **stack_b);
int			pb(t_tlist **stack_b, t_tlist **stack_a);
int			ra(t_tlist **stack_a);
int			rb(t_tlist **stack_b);
int			rr(t_tlist **stack_a, t_tlist **stack_b);
int			rra(t_tlist **stack_a);
int			rrb(t_tlist **stack_b);
int			rrr(t_tlist **stack_a, t_tlist **stack_b);

#endif
