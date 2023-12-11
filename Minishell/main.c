/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:46:42 by jooh              #+#    #+#             */
/*   Updated: 2023/12/10 20:50:06 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s1)
{
	char		*arr;
	size_t		s_len;

	s_len = strlen(s1);
	arr = calloc(s_len + 1, 1);
	if (arr == 0)
		return (0);
	memcpy(arr, s1, s_len);
	return (arr);
}

int	main(int ac, char *av[], char *envp[])
{
	int		i;
	char	**cpy;
	char	**cpy2;
	char	*buf;

	i = 0;
	buf = 0;
	if (ac == 3)
		if (chdir(av[2]) == -1)
			printf("fail\n");
	printf("%s\n", getcwd(0, 0));
	cpy = calloc(sizeof(char *) + 1, 1);
	cpy2 = calloc(sizeof(char *) + 1, 1);
	while (envp[i])
	{
		cpy[i] = ft_strdup(envp[i]);
		// printf("%s\n", envp[i]);
		cpy2[i] = cpy[i];
		i++;
	}
	if (ac == 2)
		printf("%s\n", av[1]);
	if (ac == 2)
	{
		write(1, av[1], 5);
		write(1, "\n", 1);
	}
	free(cpy);
	i = 0;
	// while (cpy2[i])
	// {
	// 	printf("%s\n", cpy2[i]);
	// 	i++;
	// }
	return (0);
}
