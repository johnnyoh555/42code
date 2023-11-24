/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:10:11 by jooh              #+#    #+#             */
/*   Updated: 2023/08/30 23:44:36 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*ret;

	ret = dest;
	while (*ret != 0)
		ret++;
	while (nb > 0)
	{
		*ret = *src;
		if (*src == 0)
			return (dest);
		ret++;
		src++;
		nb--;
	}
	*ret = 0;
	return (dest);
}
