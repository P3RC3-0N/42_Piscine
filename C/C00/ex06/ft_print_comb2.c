/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:28:33 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/03 15:33:43 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putcomb(char figure_1d, char figure_1u, char figure_2d,
	char figure_2u)
{
	ft_putchar(figure_1d);
	ft_putchar(figure_1u);
	ft_putchar(' ');
	ft_putchar(figure_2d);
	ft_putchar(figure_2u);
	if (!(figure_1d == '9' && figure_1u == '8' && figure_2d == '9'
			&& figure_2u == '9'))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_loop_print_comb2(char figure_1d, char figure_1u, char figure_2d,
	char figure_2u)
{
	while (figure_1d++ <= '9')
	{
		while (figure_1u++ <= '9')
		{		
			figure_2d = figure_1d - 1;
			figure_2u = figure_1u;
			while (figure_2d++ <= '9')
			{
				while (figure_2u++ <= '9')
				{
					ft_putcomb(figure_1d - 1,
						figure_1u - 1, figure_2d - 1,
						figure_2u - 1);
				}
				figure_2u = '0';
			}
		}
		figure_1u = '0';
	}
}

void	ft_print_comb2(void)
{
	char	figure_1d;
	char	figure_1u;
	char	figure_2d;
	char	figure_2u;

	figure_1d = '0';
	figure_1u = '0';
	figure_2d = '0';
	figure_2u = '0';
	ft_loop_print_comb2(figure_1d, figure_1u, figure_2d, figure_2u);
}

/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}*/
