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

typedef struct r_list
{
	int	value;
	int	index;
	struct r_list	*next;
}	u_list;

u_list	*ft_lstnew(int value);
u_list	*ft_lstlast(u_list *head);
void	ft_lstadd_front(u_list **stack, u_list *new);
void	ft_lstadd_back(u_list **stack, u_list *new);
void	printList(u_list *head);
int		ft_lstsize(u_list *head);

void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
int		is_sorted(u_list **stack);
int		get_distance(u_list **stack, int index);
void	make_top(u_list **stack, int distance);
void	free_stack(u_list **stack);
void	ft_free(char **str);

void	radix_sort(u_list **stack_a, u_list **stack_b);
void	simple_sort(u_list **stack_a, u_list **stack_b);
void	index_stack(u_list **stack);
void	sort_5(u_list **stack_a, u_list **stack_b);

int		swap(u_list **stack);
int		push(u_list **stack_to, u_list **stack_from);
int		rotate(u_list **stack);
int		reverserotate(u_list **stack);

int		sa(u_list **stack_a);
int		sb(u_list **stack_b);
int		ss(u_list **stack_a, u_list **stack_b);
int		pa(u_list **stack_a, u_list **stack_b);
int		pb(u_list **stack_b, u_list **stack_a);
int		ra(u_list **stack_a);
int		rb(u_list **stack_b);
int		rr(u_list **stack_a, u_list **stack_b);
int		rra(u_list **stack_a);
int		rrb(u_list **stack_b);
int		rrr(u_list **stack_a, u_list **stack_b);

char		**ft_split(char const *s, char c)
int		ft_atoi(const char *str)

#endif
