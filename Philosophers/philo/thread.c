/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:45:42 by jooh              #+#    #+#             */
/*   Updated: 2023/12/10 14:21:10 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_line(t_info *info)
{
	pthread_mutex_lock(&info->startline);
	pthread_mutex_unlock(&info->startline);
	while (1)
	{
		if (info->start <= get_time())
			break ;
		usleep(200);
	}
}

static void	*patern(void *lst)
{
	t_philo	*philo;

	philo = lst;
	start_line(philo->info);
	philo->last_eat = get_time();
	if (philo->id % 2 == 1)
		usleep(philo->info->eat_time * 500);
	while (check_end(philo->info) == 0)
	{
		if (philo->info->humans % 2 == 1
			&& philo->id == philo->info->humans - 1)
			left_handed(philo->info, philo);
		else
			right_handed(philo->info, philo);
		if (philo->info->max_eat && philo->eat == philo->info->max_eat)
			break ;
		ft_printf(philo->info, philo, "is sleeping", 3);
		time_go(philo->info, philo, philo->info->slp_time, 0);
		ft_printf(philo->info, philo, "is thinking", 2);
		usleep(200);
	}
	return (0);
}

static void	*onedog(void *lst)
{
	t_philo	*philo;

	philo = lst;
	start_line(philo->info);
	philo->last_eat = get_time();
	pthread_mutex_lock(philo->r_fork);
	if (*(philo->real_l_fork) == 0 && *(philo->real_r_fork) == 0)
	{
		if (check_dead(philo->info, philo) == 0)
		{
			printf("\e[35m%ld %d %s\e[0m\n",
				get_time() - philo->info->start, 1, "has taken a fork");
			*(philo->real_l_fork) = 1;
			*(philo->real_r_fork) = 1;
		}
	}
	pthread_mutex_unlock(philo->r_fork);
	time_go(philo->info, philo, philo->info->die_time + 100, 0);
	return (0);
}

static void	wait_thread(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->humans)
	{
		pthread_join(*(philo[i].thread), 0);
		i++;
	}
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
	pthread_mutex_unlock(&info->startline);
	wait_thread(info, philo);
	return (0);
}
