/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/25 16:14:08 by dtran         #+#    #+#                 */
/*   Updated: 2022/05/30 16:01:18 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

static void	sort_2(t_stack *a)
{
	int	idx;

	idx = 0;
	if (a->layer[idx].og_value > a->layer[idx + 1].og_value)
		ra(a);
}

static void	sort_3(t_stack *stack)
{
	int	idx;
	int	a;
	int	b;
	int	c;

	idx = 0;
	a = stack->layer[idx].og_value;
	b = stack->layer[idx + 1].og_value;
	c = stack->layer[idx + 2].og_value;
	if ((a < b) && (b > c) && (c > a))
	{
		rra(stack);
		sa(stack);
	}
	if ((a > b) && (b < c) && (c > a))
		sa(stack);
	if ((a < b) && (b > c) && (c < a))
		rra(stack);
	if ((a > b) && (b < c) && (c < a))
		ra(stack);
	if ((a > b) && (b > c) && (c < a))
	{
		sa(stack);
		rra(stack);
	}
}

static void	sort_4(t_stack *a, t_stack *b)
{
	int	position;

	position = lowest_pos(a);
	if (position == 1)
		sa(a);
	if (position == 2)
	{
		rra(a);
		rra(a);
	}
	if (position == 3)
		rra(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

static void	sort_5(t_stack *a, t_stack *b)
{
	int	position;

	position = lowest_pos(a);
	if (position == 1)
		sa(a);
	if (position == 2)
	{
		ra(a);
		ra(a);
	}
	if (position == 3)
	{
		rra(a);
		rra(a);
	}
	if (position == 4)
		rra(a);
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}

void	quicksort(t_stack *a, t_stack *b, int argc)
{
	if (argc == 3)
		sort_2(a);
	if (argc == 4)
		sort_3(a);
	if (argc == 5)
		sort_4(a, b);
	if (argc == 6)
		sort_5(a, b);
}
