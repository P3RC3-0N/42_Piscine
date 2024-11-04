/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:24:05 by ngope             #+#    #+#             */
/*   Updated: 2024/06/29 16:56:28 by ngope            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_line(char start_c, char mid_c, char end_c, int length)
{
	int	row;

	row = 0;
	while (row < length)
	{
		if (row == 0)
		{
			ft_putchar(start_c);
		}
		else if (row == length - 1)
		{
			ft_putchar(end_c);
		}
		else
		{
			ft_putchar(mid_c);
		}
		row++;
	}
	if (length > 0)
	{
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	int	col;

	col = 0;
	while (col < y)
	{
		if (col == 0)
		{
			print_line('/', '*', '\\', x);
		}
		else if (col == y - 1)
		{
			print_line('\\', '*', '/', x);
		}
		else
		{
			print_line('*', ' ', '*', x);
		}
		col++;
	}
}
