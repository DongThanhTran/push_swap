/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 13:37:16 by dtran         #+#    #+#                 */
/*   Updated: 2022/05/30 16:00:40 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix(t_stack *a, t_stack *b)
{
	int	current_bit;
	int	idx;

	current_bit = 0;
	while (current_bit < a->max_bits)
	{
		idx = 0;
		while (idx < a->length_of_arr)
		{
			if (((a->layer[0].sorted_position >> current_bit) & 1) == 0)
				pb(a, b);
			else
			{
				ra(a);
				idx++;
			}
		}
		while (b->length_of_arr > 0)
			pa(a, b);
		current_bit++;
	}
}

static void	bubble_sort_og_pos(t_stack *a)
{
	int		idx;
	int		swap_count;
	t_layer	tmp;

	swap_count = 1;
	while (swap_count > 0)
	{
		idx = 0;
		swap_count = 0;
		while (idx < a->length_of_arr - 1)
		{
			if (a->layer[idx].og_position > a->layer[idx + 1].og_position)
			{
				tmp = a->layer[idx];
				a->layer[idx] = a->layer[idx + 1];
				a->layer[idx + 1] = tmp;
				swap_count++;
			}
			idx++;
		}
	}
}

static void	bubble_sort(t_stack *a)
{
	int		idx;
	int		swap_count;
	t_layer	tmp;

	swap_count = 1;
	while (swap_count > 0)
	{
		idx = 0;
		swap_count = 0;
		while (idx < a->length_of_arr - 1)
		{
			if (a->layer[idx].og_value > a->layer[idx + 1].og_value)
			{
				tmp = a->layer[idx];
				a->layer[idx] = a->layer[idx + 1];
				a->layer[idx + 1] = tmp;
				swap_count++;
			}
			idx++;
		}
	}
	idx = -1;
	while (++idx < a->length_of_arr)
		a->layer[idx].sorted_position = idx + 1;
}

static void	init_stack(t_stack *a, t_stack *b, int argc, char *argv[])
{
	int	idx;

	idx = 0;
	a->max_bits = 0;
	a->length_of_arr = argc - 1;
	b->length_of_arr = 0;
	a->layer = ft_calloc(sizeof(t_layer), (argc -1));
	b->layer = ft_calloc(sizeof(t_layer), (argc -1));
	while (idx < argc - 1)
	{
		a->layer[idx].og_value = ft_atoi(argv[idx + 1]);
		check_max_min_int(argv[idx + 1]);
		check_duplicates(a);
		a->layer[idx].og_position = idx;
		idx++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = malloc(sizeof(t_stack));
	ft_checkmalloc(a);
	b = malloc(sizeof(t_stack));
	ft_checkmalloc(b);
	init_stack(a, b, argc, argv);
	if (is_sorted(a))
		exit (0);
	bubble_sort(a);
	a->biggest_num = a->layer[a->length_of_arr - 1].sorted_position;
	while (a->biggest_num >> a->max_bits > 0)
		a->max_bits++;
	bubble_sort_og_pos(a);
	if (argc < 7)
		quicksort(a, b, argc);
	else
		radix(a, b);
	return (0);
}
