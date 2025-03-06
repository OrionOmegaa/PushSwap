/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdescamp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:21:50 by hdescamp          #+#    #+#             */
/*   Updated: 2024/12/16 13:21:53 by hdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lsttadd_front(t_tlist **stack, t_tlist *new)
{
	new->next = *stack;
	*stack = new;
}

t_tlist	*ft_lsttlast(t_tlist *head)
{
	t_tlist	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	ft_lsttadd_back(t_tlist **stack, t_tlist *new)
{
	t_tlist	*n;

	if (*stack)
	{
		n = ft_lsttlast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

int	ft_lsttsize(t_tlist *head)
{
	size_t	i;
	t_tlist	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	print_list(t_tlist *head)
{
	t_tlist	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}
