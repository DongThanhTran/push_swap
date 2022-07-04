/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_sorted.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 15:14:22 by dtran         #+#    #+#                 */
/*   Updated: 2022/05/26 15:18:32 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	idx;

	idx = 0;
	while (idx < stack->length_of_arr - 1)
	{
		if (stack->layer[idx].og_value > stack->layer[idx + 1].og_value)
			return (0);
		idx++;
	}
	return (1);
}
