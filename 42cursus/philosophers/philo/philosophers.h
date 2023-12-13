/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:57:33 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/13 20:02:06 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILOSOPHERS_H
# define PILOSOPHERS_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_argv
{
	int			argc;
	char		**argv;
	int			numbers_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat_cnt;
	int			is_dead;
	int			all_ate;
	long long	created_time;

	pthread_mutex_t	*fork;
	pthread_mutex_t	eat;
	pthread_mutex_t	status;
}	t_argv;

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	int				last_meal;
	int				last_time;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_t		thread_id;
	t_argv			*digning;
}	t_philo; 

int	check_numeric(const char *str, int i);
int	ft_atoi(const char *str);

int	ft_init_data(t_argv *digning);

#endif