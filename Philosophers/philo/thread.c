/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:45:42 by jooh              #+#    #+#             */
/*   Updated: 2023/12/05 20:15:51 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*patern(void *lst)
{
	t_philo	*philo;

	philo = lst;
	philo->last_eat = get_time();
	if (philo->id % 2 == 1)
		usleep(philo->info->eat_time * 500);
	while (check_end(philo->info) == 0)
	{
		if (philo->id % 2 == 0)
			right_handed(philo->info, philo, 1);
		else
			left_handed(philo->info, philo, 1);
		if (philo->info->max_eat && philo->eat == philo->info->max_eat)
			break ;
		usleep(100);
		ft_printf(philo->info, philo, "is sleeping", 3);
		time_go(philo->info, philo, philo->info->slp_time, 0);
		ft_printf(philo->info, philo, "is thinking", 2);
		usleep(100);
	}
	return (0);
}

void	*onedog(void *lst)
{
	t_philo	*philo;

	philo = lst;
	philo->last_eat = get_time();
	pthread_mutex_lock(philo->r_fork);
	if (*(philo->real_l_fork) == 0 && *(philo->real_r_fork) == 0)
	{
		printf("\e[35m%ld %d %s\e[0m\n",
			get_time() - philo->info->start, 1, "has taken a fork");
		*(philo->real_l_fork) = 1;
		*(philo->real_r_fork) = 1;
	}
	pthread_mutex_unlock(philo->r_fork);
	time_go(philo->info, philo, philo->info->die_time + 100, 0);
	return (0);
}

int	sitdown(t_info *info, t_philo *philo)
{
	int	i;

	if (info->humans == 1)
	{
		if (pthread_create(philo[0].thread, 0, onedog, &(philo[0])) != 0)
			return (THREADERR);
	}
	else
	{
		i = 0;
		while (i < info->humans)
		{
			if (pthread_create(philo[i].thread, 0, patern, &(philo[i])) != 0)
				return (THREADERR);
			i++;
		}
	}
	i = 0;
	while (i < info->humans)
	{
		pthread_join(*(philo[i].thread), 0);
		i++;
	}
	return (0);
}
