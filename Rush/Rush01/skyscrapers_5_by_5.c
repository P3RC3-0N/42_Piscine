/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:07:03 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/06 15:29:06 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h> 
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_skyscraper(int base[5][5])
{
	int	i;

	i = 0;
	while (i < 25)
	{
		ft_putchar((base[i / 5][i % 5]) + 48);
		ft_putchar(' ');
		if (i % 5 == 4)
		{
			ft_putchar('\n');
		}
		i++;
	}
	i = 0;
	while (i < 25)
	{
		base[i / 5][i % 5] = -1;
		i++;
	}
}

int	its_finish(int base[5][5])
{
	int	i;

	i = 0;
	while (i < 25)
	{
		if (base[i / 5][i % 5] == -1)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	*ft_rev_int_tab(int tab[5], int size)
{
	int	tmp_value;
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i++ <= size / 2 && j-- >= size / 2)
	{
		tmp_value = tab[i - 1];
		tab[i - 1] = tab[j + 1];
		tab[j + 1] = tmp_value;
	}
	return (tab);
}

int	ft_correct_count_skyscraper(int tab[5], int correct_value)
{
	int	i;
	int	max;
	int	count;

	i = 1;
	max = tab[0];
	count = 0;
	while (i < 5)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			count++;
		}
		i++;
	}
	if (count == correct_value - 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_all_correct_count_skyscraper_row(int base[5][5], int *atoi_str, int j)
{
	int	i;
	int	tab[5];

	i = 0;
	while (i < 5)
	{
		tab[i] = base[j][i];
		i++;
	}
	if (!(ft_correct_count_skyscraper(tab, atoi_str[j + (2 * 5)])))
	{
		return (0);
	}
	if (!(ft_correct_count_skyscraper(ft_rev_int_tab(tab, 5),
				atoi_str[j + (3 * 5)])))
	{
		return (0);
	}
	return (1);
}

int	ft_all_correct_count_skyscraper_column(int base[5][5], int *atoi_str, int j)
{
	int	i;
	int	tab[5];

	i = 0;
	while (i < 5)
	{
		tab[i] = base[i][j];
		i++;
	}
	if (!(ft_correct_count_skyscraper(tab, atoi_str[j])))
	{
		return (0);
	}
	if (!(ft_correct_count_skyscraper(ft_rev_int_tab(tab, 5),
				atoi_str[j + 5])))
	{
		return (0);
	}
	return (1);
}

int	ft_all_correct_count_skyscraper(int base[5][5], int *atoi_str)
{
	int	j;

	j = 0;
	while (j < 5)
	{
		if (!ft_all_correct_count_skyscraper_row(base, atoi_str, j))
			return (0);
		if (!ft_all_correct_count_skyscraper_column(base, atoi_str, j))
			return (0);
		j++;
	}
	return (1);
}

int	free_box_skyscraper(int base[5][5], int index)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < 5)
	{
		if (i < index % 5)
		{
			if (base[index / 5][index % 5] == base[index / 5][i % 5])
			{
				return (0);
			}
		}
		if (i < index / 5)
		{
			if (base[index / 5][index % 5] == base[i][index % 5])
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

void	ft_recursive_skyscraper(int base[5][5], int *atoi_str,
				int index, int value)
{
	if (index == 25)
	{
		if (ft_all_correct_count_skyscraper(base, atoi_str))
		{
			ft_print_skyscraper(base);
			return ;
		}
	}
	else
	{		
		while (value < 6)
		{
			if (its_finish(base))
				break ;
			base[index / 5][index % 5] = value;
			if (free_box_skyscraper(base, index))
			{
				if (index % 5 == 4)
				{
					if(ft_all_correct_count_skyscraper_row(base, atoi_str, index / 5))
						ft_recursive_skyscraper(base, atoi_str, index + 1, 1);
				}
				else
					ft_recursive_skyscraper(base, atoi_str, index + 1, 1);
			}
			value++;
		}
	}
}

void	ft_skyscraper(char *str)
{
	int	base[5][5];
	int	i;
	int	atoi_str[5 * 4];

	i = 0;
	while (i < 25)
	{
		atoi_str[i] = str[i] - 48;
		i++;
	}
	ft_recursive_skyscraper(base, atoi_str, 0, 1);
	i = 0;
	while (i < 25)
	{
		if (base[i / 5][i % 5] != -1)
		{
			write(1, "Error\n", 6);
			break ;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	str_wspace[5 * 5];
	int		i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (!(i % 2))
			{
				str_wspace[i / 2] = argv[1][i];
			}
			i++;
		}
		ft_skyscraper(str_wspace);
	}
	else
	{
		write(1, "Error\n", 6);
	}
	return (0);
}
