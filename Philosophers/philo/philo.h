/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:25:54 by jooh              #+#    #+#             */
/*   Updated: 2023/12/06 17:06:19 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define ARGERR 1
# define MUTEXERR 2
# define ALLOCERR 3
# define TIMEERR 4
# define THREADERR 5

typedef struct s_info
{
	int				humans;
	long			die_time;
	long			eat_time;
	long			slp_time;
	int				max_eat;
	long			start;
	pthread_mutex_t	printer;
	pthread_mutex_t	*fork;
	pthread_mutex_t	startline;
	int				*real_fork;
	int				end_flag;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	int				eat;
	int				id;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	int				*real_r_fork;
	int				*real_l_fork;
	long			last_eat;
	pthread_t		*thread;
}	t_philo;

// main.c
int		err_seq(t_info *info, t_philo *philo, int i);
void	ft_printf(t_info *info, t_philo *philo, char *str, int flag);
int		time_go(t_info *info, t_philo *philo, long sleep, int i);
int		check_end(t_info *info);

// thread.c
int		sitdown(t_info *info, t_philo *philo);
void	*patern(void *lst);
void	*onedog(void *lst);

// parsing.c
int		init_info(t_info *info, char *av[], int ac);
int		make_forks(t_info *info);
int		make_philos(t_info *info, t_philo *philo);
long	get_time(void);
void	end_seq(t_info *info, t_philo *philo);

// atoi.c
int		ft_atoi(char *str);
int		check_size(char *str, int minus, int i);
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_dead(t_info *info, t_philo *philo);

// eating.c
void	right_handed(t_info *info, t_philo *philo);
void	left_handed(t_info *info, t_philo *philo);
int		time_to_eat_r(t_info *info, t_philo *philo);
int		time_to_eat_l(t_info *info, t_philo *philo);

#endif