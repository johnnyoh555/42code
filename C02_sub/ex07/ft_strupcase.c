/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:56:13 by jooh              #+#    #+#             */
/*   Updated: 2023/08/29 19:32:04 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*ret;

	ret = str;
	while (*str != 0)
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str + 'A' - 'a';
		str++;
	}
	str = ret;
	return (str);
}
