/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:58:25 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/03 20:58:28 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_c_is_printable(char c)
{
	if (!(c >= 32 && c <= 126))
	{
		return (0);
	}
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	char	*base;

	base = "0123456789abcdef";
	while (*str)
	{
		if (!(ft_c_is_printable(*str)))
		{
			ft_putchar('\\');
			ft_putchar(base[(unsigned char)*str / 16]);
			ft_putchar(base[(unsigned char)*str % 16]);
		}
		else
			ft_putchar(*str);
		str++;
	}
}

/*
int	main(void)
{
	char	*sentence;
	
	sentence = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(sentence);
	return (0);
}*/
