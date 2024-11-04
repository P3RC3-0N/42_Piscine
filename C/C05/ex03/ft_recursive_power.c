/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 03:41:45 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/11 03:41:48 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{	
	if (power < 0)
		return (0);
	else if (power == 0)
	{
		return (1);
	}
	else
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
}

/*
int	main(void)
{
	printf("result : %d\n", ft_recursive_power(0, 0));
	printf("result : %d\n", ft_recursive_power(10, 0));
	printf("result : %d\n", ft_recursive_power(0, 10));
	printf("result : %d\n", ft_recursive_power(2, 2));
	printf("result : %d\n", ft_recursive_power(2, -2));
	return (0);
}*/
