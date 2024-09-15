/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:23:53 by rdalal            #+#    #+#             */
/*   Updated: 2024/07/11 20:23:53 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <limits.h>
# include "../push_swap/libft/libft.h"
# include <string.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int				error_syntax(char *str_n);

int				error_dup(t_stack_node *a, int n);

int				stack_len(t_stack_node *stack);

int				main(int argc, char **argv);

bool			sorted_stack(t_stack_node *stack);

void			pa(t_stack_node **a, t_stack_node **b, bool print);

void			pb(t_stack_node **b, t_stack_node **a, bool print);

void			ra(t_stack_node **a, bool print);

void			rb(t_stack_node **b, bool print);

void			rr(t_stack_node **a, t_stack_node **b, bool print);

void			rra(t_stack_node **a, bool print);

void			rrb(t_stack_node **b, bool print);

void			rrr(t_stack_node **a, t_stack_node **b, bool print);

void			free_stack(t_stack_node **stack);

void			free_errors(t_stack_node **a);

void			current_index(t_stack_node *stack);

void			init_nodes_a(t_stack_node *a, t_stack_node *b);

void			init_nodes_b(t_stack_node *a, t_stack_node *b);

void			init_stack_a(t_stack_node **a, char **argv);

void			prep_for_push(t_stack_node **stack,
					t_stack_node *top_node, char stack_name);

t_stack_node	*get_cheapest(t_stack_node *stack);

t_stack_node	*get_last(t_stack_node *stack);

t_stack_node	*get_min(t_stack_node *stack);

t_stack_node	*get_max(t_stack_node *stack);

#endif

//handle errors

//stack initiation

//nodes initiation

//stack utils

//commands

//algorithms