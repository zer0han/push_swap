/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:41:37 by rdalal            #+#    #+#             */
/*   Updated: 2024/09/06 18:42:31 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*push;

	if (!*src)
		return ;
	push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push -> prev = NULL;
	if (!*dest)
	{
		*dest = push;
		push -> next = NULL;
	}
	else
	{
		push -> next = *dest;
		push -> next -> prev = push;
		*dest = push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
