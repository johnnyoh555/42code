/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:19:59 by jooh              #+#    #+#             */
/*   Updated: 2023/12/12 11:55:02 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	err_seq(char *str, char *err, int ex, int flag)
{
	if (err == 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(err, 2);
		ft_putstr_fd("\n", 2);
	}
	if (flag)
		return (ex);
	exit(ex);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (1)
	{
		if (*str1 == 0 && *str2 == 0)
			return (0);
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	i;

	if (!count || !size)
		return (malloc(0));
	if (size > -1 / count)
		return (0);
	i = count * size;
	arr = malloc(sizeof(char) * i);
	if (arr == 0)
		err_seq("malloc", 0, 1, 0);
	ft_bzero(arr, i);
	return (arr);
}
