/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:45:34 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/03 15:38:25 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_combination(char *tab, int size, int indice, char c)
{
	char	i;

	if (indice == size)
	{
		write(1, tab, size);
		if (!(tab[0] == '9' - size + 1 && tab[size - 1] == '9'))
			write(1, ", ", 2);
		return ;
	}
	i = c;
	while (i <= '9')
	{
		tab[indice] = i;
		ft_combination(tab, size, indice + 1, i + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	tab[9];

	ft_combination(tab, n, 0, '0');
}

/*
int	main(void)
{
	ft_print_combn(2);
	return (0);
}*/
