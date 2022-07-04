/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 17:24:17 by dtran         #+#    #+#                 */
/*   Updated: 2022/05/25 16:51:14 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack *stack)
{
	int		idx;
	t_layer	tmp;

	idx = 0;
	tmp = stack->layer[0];
	while (idx < stack->length_of_arr - 1)
	{
		stack->layer[idx] = stack->layer[idx + 1];
		idx++;
	}
	stack->layer[stack->length_of_arr - 1] = tmp;
}

void	ra(t_stack *a)
{
	rotate(a);
	write (1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b);
	write (1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write (1, "rr\n", 3);
}
