/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 13:31:24 by dtran         #+#    #+#                 */
/*   Updated: 2022/05/27 16:58:05 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <libft.h>
# include <limits.h>

typedef struct s_layer
{
	int	og_value;
	int	sorted_position;
	int	og_position;
}	t_layer;

typedef struct s_stack
{
	t_layer	*layer;
	int		length_of_arr;
	int		biggest_num;
	int		max_bits;
}	t_stack;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	check_max_min_int(char *num);
void	check_duplicates(t_stack *a);
int		lowest_num(t_stack *a);
int		lowest_pos(t_stack *a);

void	quicksort(t_stack *a, t_stack *b, int argc);
int		is_sorted(t_stack *stack);

#endif
