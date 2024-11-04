/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:50:42 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/01 20:37:40 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strc(char *str, char c, int nb_occ)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{				
		if (str[i] == c)
		{
			count++;
		}
		if (count == nb_occ)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

void	ft_recursive_putnbr_base(unsigned int nbr, unsigned int len_base,
							char *base)
{
	if (nbr / len_base != 0)
	{
		ft_recursive_putnbr_base(nbr / len_base, len_base, base);
		ft_putchar(base[nbr % len_base]);
	}
	else
	{
		ft_putchar(base[nbr]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				i;
	int				no_unique;
	unsigned int	nbr_u;

	no_unique = 0;
	i = 0;
	if (!(ft_strlen(base) < 2 || ft_strc(base, '+', 1)
			|| ft_strc(base, '-', 1)))
	{
		while (base[i] && no_unique == 0)
			no_unique = ft_strc(base, base[i++], 2);
		if (no_unique == 0)
		{
			if (nbr < 0)
			{
				ft_putchar('-');
				nbr_u = -nbr;
			}
			else
				nbr_u = nbr;
			ft_recursive_putnbr_base(nbr_u, ft_strlen(base), base);
		}
	}
}

/*
int	main(void)
{
	write(1, "test1", 5);
	ft_putnbr_base(-64, "abcde");
	ft_putchar('\n');
	write(1, "test2", 5);
	ft_putnbr_base(-2147483648, "abcde");
	ft_putchar('\n');
	write(1, "test3", 5);
	ft_putnbr_base(2147483647, "abcde");
	ft_putchar('\n');
	write(1, "test4", 5);
	ft_putnbr_base(-64, "acbcde");
	ft_putchar('\n');
	write(1, "test5", 5);
	ft_putnbr_base(-64, "abc+de");
	ft_putchar('\n');
	write(1, "test6", 5);
	ft_putnbr_base(-64, "a-bcde");
	ft_putchar('\n');
	write(1, "test7", 5);
	ft_putnbr_base(-64, "");
	ft_putchar('\n');
	write(1, "test8", 5);
	ft_putnbr_base(-64, "a");
	return (0);
}*/
