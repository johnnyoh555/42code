/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:01:22 by jooh              #+#    #+#             */
/*   Updated: 2023/08/30 21:20:32 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_1(char *str, char *to_find)
{
	char	*ret;

	ret = str;
	while (*to_find != 0)
	{
		if (*ret != *to_find)
			return (0);
		ret++;
		to_find++;
	}
	return (str);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*p;

	if (*to_find == 0)
		return (str);
	while (*str != 0)
	{
		if (*str == *to_find)
		{
			p = ft_1(str, to_find);
			if (p != 0)
				return (p);
		}
		str++;
	}
	return (0);
}
