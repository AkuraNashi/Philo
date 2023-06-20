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

/// Check numbers
/// \param av char containing numbers
/// \return 1 if allowed
int check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

/// Owned atoi coded
/// \param str convert to int
/// \return number converted
int	ft_atoi(const char *str)
{
	unsigned int	toreturn;
	int				negative;

	toreturn = 0;
	negative = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			negative *= -1;
	while (*str >= '0' && *str <= '9')
		toreturn = toreturn * 10 + (*(str++) - '0');
	return (toreturn * negative);
}