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

void	init_args(int ac, char **av, t_simulation *game)
{
	game->args.nb_philos = ft_atoi(av[1]);
	game->args.time_die = ft_atoi(av[2]);
	game->args.time_eat = ft_atoi(av[3]);
	game->args.time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		game->args.nb_must_eat = ft_atoi(av[5]);
	else
		game->args.nb_must_eat = 0;
}