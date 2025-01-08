/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdescamp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:33:00 by hdescamp          #+#    #+#             */
/*   Updated: 2025/01/08 14:26:51 by hdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_tlist **stack)
{
	t_tlist	*head;
	t_tlist	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lsttsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		ft_error("Error occured while swapping!");
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	push(t_tlist **stack_to, t_tlist **stack_from)
{
	t_tlist	*tmp;
	t_tlist	*head_to;
	t_tlist	*head_from;

	if (ft_lsttsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

int	rotate(t_tlist **stack)
{
	t_tlist	*head;
	t_tlist	*tail;

	if (ft_lsttsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lsttlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	reverserotate(t_tlist **stack)
{
	t_tlist	*head;
	t_tlist	*tail;

	if (ft_lsttsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lsttlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			 head->next = NULL;
			 break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rrr(t_tlist **stack_a, t_tlist **stack_b)
{
	if ((ft_lsttsize(*stack_a) < 2) || (ft_lsttsize(*stack_b) < 2))
		return (-1);
	reverserotate(stack_a);
	reverserotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
