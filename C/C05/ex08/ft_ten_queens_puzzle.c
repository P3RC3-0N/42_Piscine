/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 00:33:56 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/02 00:33:58 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>

int	ft_free_box(int row, int column, int *tab)
{
	int	i;

	i = 0;
	while (i < column)
	{
		if ((tab[i] == row) || (row - tab[i] == column - i)
			|| (row - tab[i] == i - column))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_print_tab(int *tab)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = tab[i] + 48;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_recursive_ten_queens_puzzle(int row,
		int column, int *tab, int *count)
{
	if (column == 10)
	{
		(*count)++;
		ft_print_tab(tab);
	}
	else
	{
		while (row < 10)
		{
			if (ft_free_box(row, column, tab))
			{
				tab[column] = row;
				ft_recursive_ten_queens_puzzle(0, column + 1, tab, count);
			}
			row++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	tab[10];
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < 10)
	{
		tab[i] = 0;
		i++;
	}
	ft_recursive_ten_queens_puzzle(0, 0, tab, &count);
	return (count);
}

/*
int	main(void)
{
	printf("nb : %d\n", ft_ten_queens_puzzle());
	return (0);
}*/
