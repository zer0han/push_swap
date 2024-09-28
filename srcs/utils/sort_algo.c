/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:52:18 by rdalal            #+#    #+#             */
/*   Updated: 2024/09/16 09:52:18 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_two(t_stack_node **a, t_stack_node **b, t_stack_node *chep)
{
	while (*a != chep && *b != chep->target_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	reve_rotate(t_stack_node **a, t_stack_node **b, t_stack_node *chep)
{
	while (*a != chep && *b != chep->target_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	push_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_two(a, b, cheapest);
	else if (!(cheapest->above_median) && \
	!(cheapest->target_node->above_median))
		reve_rotate(a, b, cheapest);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target_node, 'b');
	pb(b, a, false);
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != get_min(*a)->nbr)
	{
		if (get_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_algo(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_len(*a);
	if (len-- > 3 && !sorted_stack(*a))
		pb(b, a, false);
	while (len-- > 3 && !sorted_stack(*a))
	{
		init_nodes_a(*a, *b);
		push_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		prep_for_push(a, (*b)->target_node, 'a');
		pa(a, b, false);
	}
	current_index(*a);
	min_on_top(a);
}
