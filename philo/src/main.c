/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:17:16 by lcamilo-          #+#    #+#             */
/*   Updated: 2023/01/16 11:17:18 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_error(t_simulation *simu, char *msg)
{
	(void) simu;
	printf("%s\n", msg);
}

long long time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000  + time.tv_usec / 1000);
}

void	init_philo(t_simulation *simu)
{
	int i;

	i = 0;
	while (i < simu->args.nb_philos)
	{
		simu->philo[i].id = i + 1;
		simu->philo[i].last_meal = time_ms();
		i++;
	}
}

int init_simu(t_simulation *simu)
{
	simu->count = 0;
	simu->philo = malloc(sizeof(t_philo) * simu->args.nb_philos);
	if (!simu->philo)
		return (1);
	return (0);
}

void	start_simulation(t_simulation *simu)
{
	t_philo *philo;

	philo = simu->philo;
//	while (philo)
//	{
//
//	}
}

void	*routine()
{
	int dice = (rand() % 6) + 1;
	int *res = malloc(sizeof(int));
	*res = dice;
	return ((void *) res);
}

int main (int ac, char **av)
{
	t_simulation	simu;

	if (ac < 5 || ac > 6)
	{
		printf(" Usage : ./philo Nb_Philo time_die time_eat time_sleep"
			   " [nb_time_must_eat]\n");
		return (1);
	}
	if (!check_args(av))
	{
		printf("Numbers can't be negative or 0\n");
		return (1);
	}
	init_args(ac, av, &simu);
	if (init_simu(&simu))
		return (1);
	init_philo(&simu);
	if (pthread_create(&simu.philo->thread, NULL, &routine, NULL))
		return (1);
	if (pthread_join(simu.philo->thread, (void **) &simu.count))
		return (1);
	printf("dice [%d]\n", *simu.count);
//	start_simulation(simu);
	return (0);
}