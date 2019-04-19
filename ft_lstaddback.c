/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstaddback.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 21:19:20 by jesmith        #+#    #+#                */
/*   Updated: 2019/04/19 10:54:18 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddback(t_list **alst, t_list *blst)
{
	t_list *temp;

	if (temp == NULL)
	{
		*alst = blst;
		return (blst);
	}
	temp = *alst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = blst;
	return (blst);
}
