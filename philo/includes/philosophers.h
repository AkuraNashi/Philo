/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  philosophers.h 	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:21:40 by lcamilo-          #+#    #+#             */
/*   Updated: 2023/01/16 11:21:41 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_args
{
	int            nb_philos;
	long long    time_die;
	long long    time_eat;
	long long    time_sleep;
	int        nb_must_eat;
}    t_args;

typedef struct s_philo
{
	int                id;
	long long        last_meal;
	pthread_t		thread;
}	t_philo;

typedef struct s_simulation
{
	t_args		args;
	t_philo		*philo;
	pthread_mutex_t mutex;
	int	*count;
}	t_simulation;

/////////////////////////////UTILS.C////////////////////////////////////////////
int		ft_atoi(const char *str);
int 	check_args(char **av);
//////////////////////////////INIT.C////////////////////////////////////////////
void	init_args(int ac, char **av, t_simulation *game);

#endif