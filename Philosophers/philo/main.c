/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:24:59 by jooh              #+#    #+#             */
/*   Updated: 2023/12/02 19:22:01 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_end(t_info *info)
{
	pthread_mutex_lock(&info->printer);
	if (info->end_flag == 1)
	{
		pthread_mutex_unlock(&info->printer);
		return (1);
	}
	pthread_mutex_unlock(&info->printer);
	return (0);
}

int	time_go(t_info *info, t_philo *philo, long sleep, int i)
{
	long	now;
	long	start;

	if (check_end(info))
		return (1);
	if (i)
		philo->last_eat = get_time();
	start = get_time();
	if (start + sleep > philo->last_eat + info->die_time)
		usleep(sleep * 800);
	while (1)
	{
		now = get_time();
		if (now - philo->last_eat >= info->die_time)
		{
			ft_printf(info, philo, "died", 1);
			return (1);
		}
		if (sleep == 0 || now - start >= sleep)
			break ;
		usleep(100);
	}
	return (0);
}

void	ft_printf(t_info *info, t_philo *philo, char *str, int flag)
{
	int	id;

	id = philo->id + 1;
	pthread_mutex_lock(&info->printer);
	if (flag == 0 && info->end_flag == 0)
	{
		printf("\e[32m%ld %d %s\e[0m\n", get_time() - info->start, id, str);
		philo->eat++;
	}
	else if (flag == 1 && info->end_flag == 0)
	{
		printf("\e[31m%ld %d %s\e[0m\n", get_time() - info->start, id, str);
		info->end_flag = 1;
	}
	else if (flag == 2 && info->end_flag == 0)
		printf("\e[33m%ld %d %s\e[0m\n", get_time() - info->start, id, str);
	else if (flag == 3 && info->end_flag == 0)
		printf("\e[34m%ld %d %s\e[0m\n", get_time() - info->start, id, str);
	else if (flag == 4 && info->end_flag == 0)
	{
		printf("\e[35m%ld %d %s\e[0m\n", get_time() - info->start, id, str);
		printf("\e[35m%ld %d %s\e[0m\n", get_time() - info->start, id, str);
	}
	pthread_mutex_unlock(&info->printer);
}

int	err_seq(t_info *info, t_philo *philo, int i)
{
	char	*str;

	end_seq(info, philo);
	if (i == 1)
		str = "argument: wrong arguments";
	else if (i == 2)
		str = "mutex: fail to make mutex";
	else if (i == 3)
		str = "malloc: fail to allocate";
	else if (i == 4)
		str = "gettimeofday: fail to get time";
	else
		str = "thread: fail to create a thread";
	printf("\e[31mphilo: %s\e[0m\n", str);
	return (i);
}

int	main(int ac, char *av[])
{
	t_philo	*philo;
	t_info	info;
	int		i;

	philo = 0;
	memset(&info, 0, sizeof(t_info));
	if ((ac != 5 && ac != 6) || init_info(&info, av, ac))
		return (err_seq(&info, philo, ARGERR));
	i = make_forks(&info);
	if (i)
		return (err_seq(&info, philo, i));
	philo = malloc(sizeof(t_philo) * info.humans);
	if (philo == 0)
		return (err_seq(&info, philo, ALLOCERR));
	i = make_philos(&info, philo);
	if (i)
		return (err_seq(&info, philo, i));
	i = sitdown(&info, philo);
	end_seq(&info, philo);
	return (0);
}
