/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 03:42:24 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/11 03:42:26 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_high_sqrt(int nb)
{	
	int	i;

	if (nb < 0)
		return (0);
	else if (nb == 1)
		return (1);
	else
	{	
		i = 2;
		while (i * i < nb && i < 46341)
			i++;
	}
	if (i * i == nb)
		return (i);
	else
		return (i - 1);
}

int	ft_is_prime(int nb)
{	
	int	i;
	int	i_sqrt;

	i = nb;
	if (nb < 2)
		return (0);
	else
	{
		i_sqrt = ft_high_sqrt(i);
		while (i_sqrt != 1)
		{
			if (nb % i_sqrt == 0)
				return (0);
			i_sqrt--;
		}
		return (1);
	}
}

/*
int	main(void)
{
	printf("result : %d\n", ft_is_prime(3));
	return (0);
}*/
