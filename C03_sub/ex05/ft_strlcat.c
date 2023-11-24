/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:22:49 by jooh              #+#    #+#             */
/*   Updated: 2023/09/02 13:11:25 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *dest)
{
	unsigned int	i;

	i = 0;
	while (*dest != 0)
	{
		dest++;
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dlen;
	unsigned int	slen;
	unsigned int	i;

	i = size;
	dlen = str_len(dest);
	slen = str_len(src);
	if (size > dlen)
	{		
		dest += dlen;
		while (i - dlen > 1 && *src != 0)
		{
			*dest = *src;
			dest++;
			src++;
			i--;
		}
		*dest = 0;
		return (slen + dlen);
	}
	return (slen + size);
}
