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

static int	valid_input(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			return (0);
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
			return ;
		if (!valid_input(split_argv))
		{
			free_split(split_argv, argc);
			free_errors(a);
			return ;
		}
		init_stack_a(a, split_argv);
		free_split(split_argv, argc);
	}
	else
	{
		if (!valid_input(argv + 1))
		{
			free_errors(a);
			return ;
		}
		init_stack_a(a, argv + 1);
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
