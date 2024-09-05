/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:04:18 by rdalal            #+#    #+#             */
/*   Updated: 2024/09/03 18:26:18 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			i;

	while (b)
	{
		i = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a -> nbr > b -> nbr && current_a -> nbr < i)
			{
				i = current_a -> nbr;
				target_node = current_a;
			}
			current_a = current_a -> next;
		}
		if (i == LONG_MAX)
			b -> target_node = find_min(a);
		else
			b -> target_node;
		b = b -> next;
	}	
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	target_b(a, b);
}
