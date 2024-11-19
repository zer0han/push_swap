/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:00:44 by rdalal            #+#    #+#             */
/*   Updated: 2024/07/12 13:00:44 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	valid_input(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			return (0);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (0);
		if (error_dup(*a, (int)n))
			return (0);
		append_node(a, (int)n);
		i++;
	}
	return (1);
}

static void	handle_cases(t_stack_node **a, int argc, char **argv)
{
	char	**split_argv;

	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
			free_errors(a);
		if (!valid_input(a, split_argv))
		{
			free_split(split_argv, ft_word_count(argv[1], ' '));
			free_stack(a);
			free_errors(a);
		}
		free_split(split_argv, ft_word_count(argv[1], ' '));
		split_argv = NULL;
	}
	else
	{
		if (!valid_input(a, argv + 1))
		{
			free_stack(a);
			free_errors(a);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	handle_cases(&a, argc, argv);
	if (!sorted_stack(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_algo(&a, &b);
		else
			sort_algo(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
