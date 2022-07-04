/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/25 14:31:13 by dtran         #+#    #+#                 */
/*   Updated: 2022/05/30 15:36:51 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_max_min_int(char *num)
{
	int	idx;

	idx = 0;
	if (ft_atoi(num) > INT_MAX || ft_atoi(num) < INT_MIN)
		ft_error_exit("Error", 1);
	if (num[0] == '-')
		idx++;
	while (num[idx])
	{
		if (num[idx] < '0' || num[idx] > '9')
			ft_error_exit("Error", 1);
		idx++;
	}
}

void	check_duplicates(t_stack *a)
{
	int	idx1;
	int	idx2;

	idx1 = 0;
	while (a->layer[idx1].og_value)
	{
		idx2 = idx1 + 1;
		while (idx2 < a->length_of_arr)
		{
			if (a->layer[idx1].og_value == a->layer[idx2].og_value)
				ft_error_exit("Error", 1);
			idx2++;
		}
		idx1++;
	}
}

int	lowest_num(t_stack *a)
{
	int	idx;
	int	lowest;

	idx = 0;
	lowest = INT_MAX;
	while (idx <= a->length_of_arr - 1)
	{
		if (a->layer[idx].og_value < lowest)
			lowest = a->layer[idx].og_value;
		idx++;
	}
	return (lowest);
}

int	lowest_pos(t_stack *a)
{
	int	lowest;
	int	position;
	int	idx;

	lowest = lowest_num(a);
	position = 0;
	idx = 0;
	while (a->layer[idx].og_value > lowest)
	{
		position++;
		idx++;
	}
	return (position);
}
