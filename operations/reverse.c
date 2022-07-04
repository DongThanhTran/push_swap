/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/25 17:21:36 by dtran         #+#    #+#                 */
/*   Updated: 2022/05/26 13:25:11 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse(t_stack *stack)
{
	int		idx;
	t_layer	tmp;
	t_layer	tmp2;

	idx = stack->length_of_arr - 1;
	tmp = stack->layer[stack->length_of_arr - 1];
	while (idx > 0)
	{
		stack->layer[idx] = stack->layer[idx - 1];
		idx--;
	}
	stack->layer[0] = tmp;
}

void	rra(t_stack *a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}
