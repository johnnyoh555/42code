/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:12:08 by jooh              #+#    #+#             */
/*   Updated: 2023/10/09 19:13:45 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		i;

	p = lst;
	i = 1;
	if (!lst)
		return (0);
	while (p->next)
	{
		p = p->next;
		i++;
	}
	return (i);
}
