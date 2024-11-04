/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:11:43 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/03 21:11:46 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putc_non_printable_point(char c)
{
	char	*base;

	base = "0123456789abcdef";
	if (!(c >= 32 && c <= 126))
	{
		ft_putchar('.');
	}
	else
		ft_putchar(c);
}

void	ft_print_address(unsigned long long cast_addr, char *base,
		unsigned int i)
{
	int	j;

	j = 16 - 1;
	if (i != 0)
	{
		ft_print_address(cast_addr / 16, base, i - 1);
	}
	ft_putchar(base[cast_addr % 16]);
	if (i == 16 - 1)
		ft_putchar(':');
}

void	ft_print2c_memory(int size, char *sentence, int j, int i)
{
	while (i < size)
	{
		if (i % 16 == 0)
		{
			if (i != 0)
				ft_putchar('\n');
			ft_print_address((unsigned long long)(sentence + i),
				"0123456789abcdef", 16 - 1);
		}
		if ((i % 2) == 0)
			ft_putchar(' ');
		ft_putchar("0123456789abcdef"[(int)sentence[i] / 16]);
		ft_putchar("0123456789abcdef"[(int)sentence[i] % 16]);
		if (i % 16 == 15)
		{
			ft_putchar(' ');
			j = i - 16 + 1;
			while (j++ <= i)
				ft_putc_non_printable_point(sentence[j - 1]);
			j = 0;
		}
	i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	j;
	char			*sentence;

	sentence = addr;
	ft_print2c_memory(size, sentence, 0, 0);
	j = size % 16;
	while (j != 0 && j++ < 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if ((j - 1) % 2)
			ft_putchar(' ');
	}
	j = (size / 16) * 16;
	while (j++ != size)
	{
		if (!(sentence[j - 1] >= 32 && sentence[j - 1] <= 126))
			ft_putchar('.');
		else
			ft_putchar(sentence[j - 1]);
	}
	if (size != 0)
		ft_putchar('\n');
	return (addr);
}

/*
int	main(void)
{
	char	*tab;

	tab = "Bonjour a tou";
	ft_print_memory(tab, 13);
	return (0);
}*/
