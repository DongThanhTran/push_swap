/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dtran <dtran@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 16:40:52 by dtran         #+#    #+#                 */
/*   Updated: 2021/11/01 14:43:12 by dtran         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}