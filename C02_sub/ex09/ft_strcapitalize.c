/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:27:16 by jooh              #+#    #+#             */
/*   Updated: 2023/08/28 21:37:48 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char *str)
{
	int	i;

	i = 0;
	str--;
	if (*str < 'a' || *str > 'z')
		i++;
	if (*str < 'A' || *str > 'Z')
		i++;
	if (*str < '0' || *str > '9')
		i++;
	return (i);
}

void	lower(char *str)
{
	while (*str != 0)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = *str - ('A' - 'a');
		str++;
	}
}

char	*ft_strcapitalize(char *str)
{
	char	*ret;
	int		i;

	ret = str;
	lower(str);
	while (*str != 0)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			i = check(str);
			if (i == 3)
				*str = *str + 'A' - 'a';
		}
		str++;
	}
	str = ret;
	return (str);
}
