/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 13:12:14 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/08 10:31:20 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(const char *s)
{
	if (*s == '\0')
		ft_memdel((void **)(s));
}
