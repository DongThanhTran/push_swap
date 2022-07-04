/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 16:44:10 by dtran         #+#    #+#                 */
/*   Updated: 2022/05/30 16:01:49 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack *a, t_stack *b)
{
	int	idx;

	idx = a->length_of_arr;
	if (!(b->length_of_arr))
		return ;
	while (idx > 0)
	{
		a->layer[idx] = a->layer[idx - 1];
		idx--;
	}
	a->layer[0] = b->layer[0];
	a->length_of_arr++;
	b->length_of_arr--;
	while (idx <= b->length_of_arr)
	{
		b->layer[idx] = b->layer[idx + 1];
		idx++;
	}
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
