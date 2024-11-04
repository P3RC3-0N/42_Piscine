/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:50:17 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/04 17:50:20 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
	{
		return (1);
	}
	else
	{
		while (power != 0)
		{
			result *= nb;
			power--;
		}
	}
	return (result);
}

/*
int	main(void)
{
	printf("result : %d\n", ft_iterative_power(-5, -2));
	printf("result : %d\n", ft_iterative_power(-5, 0));
	printf("result : %d\n", ft_iterative_power(-5, 2));
	printf("result : %d\n", ft_iterative_power(0, -2));
	printf("result : %d\n", ft_iterative_power(0, 0));
	printf("result : %d\n", ft_iterative_power(0, 2));
	printf("result : %d\n", ft_iterative_power(5, -2));
	printf("result : %d\n", ft_iterative_power(5, 0));
	printf("result : %d\n", ft_iterative_power(5, 2));
	return (0);
}*/
