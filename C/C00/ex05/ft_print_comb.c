/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:04:43 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/03 15:39:53 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_all_putchar(char figure1, char figure2, char figure3)
{	
	write(1, &figure1, 1);
	write(1, &figure2, 1);
	write(1, &figure3, 1);
	if (figure1 != '7')
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb(void)
{
	char	figure1;
	char	figure2;
	char	figure3;

	figure1 = '0';
	while (figure1 <= '7')
	{
		figure2 = figure1 + 1;
		while (figure2 <= '8')
		{
			figure3 = figure2 + 1;
			while (figure3 <= '9')
			{
				ft_all_putchar(figure1, figure2, figure3);
				figure3++;
			}
			figure2++;
		}	
		figure1++;
	}
}

/*
int	main(void)
{
	ft_print_comb();
	return (0);
}*/
