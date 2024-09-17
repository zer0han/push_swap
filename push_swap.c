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

#include "push_swap.h"

/* psudo code
* Declare pointers to the 2 data structures/linked lists, one for stack 'a' and one for 'b'
** set both pointers to NULL to avoid undefined behaviour and indicate we're starting with empty stacks
* Handle input count errors, argument count must be 2 or more, and the second input must not be empty
** if input of numbers is a string, call split () to split the substrings
* initialize stack 'a' by appending each input number as a node to stack 'a'
** handle integer overflow, duplicates, and syntax errors, input should only have digits and '-' & '+' signs
*** if error free stack 'a' and return error
** check for each input, if it is a long integer
*** if input is string convert into long integer
** append the nodes to stack 'a'
* check if stack 'a' is sorted
** if not sorted implement our sorting algorithm
*** check for 2 numbers 
**** if so simply swap the numbers
*** check for 3 numbers
**** if so, implement sort three algo
*** check if the stack has more than 3 numbers
**** if so implement turk algo need to write your own algo
*/

/* utils
* function to handle errors
* operations
* stack length
* last node
* min and max nodes
*/
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if (!sorted_stack(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_algo(&a, &b);
	}
	free_stack(&a);
	return (0);
}
