/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:12:16 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/03 15:36:16 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{	
	unsigned int	nbr_u;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr_u = -nbr;
	}
	else
	{
		nbr_u = nbr;
	}
	if (nbr_u / 10 > 0)
	{
		ft_putnbr(nbr_u / 10);
	}
	ft_putchar(nbr_u % 10 + 48);
}

/*
int	main(void)
{
	int	nbr;

	nbr = 15676876;
	ft_putnbr(nbr);
}*/
