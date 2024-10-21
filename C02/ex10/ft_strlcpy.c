/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:41:04 by jooh              #+#    #+#             */
/*   Updated: 2023/08/28 23:16:02 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	up(char *dest, char *src, unsigned int size)
{
	while (size > 1)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = 0;
}

void	low(char *dest, char *src, unsigned int len)
{
	while (len > 0)
	{
		*dest = *src;
		dest++;
		src++;
		len--;
	}
	*dest = 0;
}

int	str_len(char *src)
{
	unsigned int	len;

	len = 0;
	while (*src != 0)
	{
		len++;
		src++;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;

	len = str_len(src);
	if (len < size)
		low(dest, src, len);
	else
		up(dest, src, size);
	return (len);
}
