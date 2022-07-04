/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 16:39:04 by dtran         #+#    #+#                 */
/*   Updated: 2022/05/30 15:06:53 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	idx;
	long	res;
	long	sign;

	idx = 0;
	res = 0;
	sign = 1;
	while (ft_isspace((str[idx])))
	{
		idx++;
	}
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (ft_isdigit(str[idx]))
	{
		res = res * 10 + str[idx] - '0';
		idx++;
	}
	return (sign * res);
}

// COMMENTS:

// res = res * 10 + str[i] - '0';
// - '0' to make char to int
// res * 10 to go to the following place in the number
// that will be converted to an int.