/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:58:03 by jooh              #+#    #+#             */
/*   Updated: 2023/08/29 22:08:45 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*ret;

	ret = dest;
	while (*ret != 0)
		ret++;
	while (*src != 0)
	{
		*ret = *src;
		ret++;
		src++;
	}
	*ret = 0;
	return (dest);
}
