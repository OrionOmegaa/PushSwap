/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdescamp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:56:48 by hdescamp          #+#    #+#             */
/*   Updated: 2025/02/03 14:26:24 by hdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	int			i;
	long long	tmp;
	char		**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoll(args[i]);
		if (!ft_isnum(args[i]))
			ft_error("Error");
		if (ft_contains(tmp, args, i))
			ft_error("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Error");
		i++;
	}
	if (argc == 2)
		ft_free_split(args);
}

int	get_min(t_tlist **stack, int val)
{
	t_tlist	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

long long	ft_atoll(const char *str)
{
	t_tlist	list;

	list.sign = 1;
	list.result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			list.sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (list.result > (LLONG_MAX / 10) || (list.result == LLONG_MAX / \
				10 && (*str - '0') > LLONG_MAX % 10))
		{
			if (list.sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		list.result = list.result * 10 + (*str++ - '0');
	}
	return (list.result * list.sign);
}
