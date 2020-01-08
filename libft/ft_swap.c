/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 12:23:14 by jesmith        #+#    #+#                */
/*   Updated: 2019/02/21 13:44:21 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int x;

	x = *a;
	*a = *b;
	*b = x;
}
