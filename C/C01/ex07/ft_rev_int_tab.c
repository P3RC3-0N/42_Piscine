/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:05:12 by thtricar          #+#    #+#             */
/*   Updated: 2024/06/28 14:33:59 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
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
}

/*
int	main(void)
{
	int	tab[5];
	int	 size;
	int	i;
	
	i = 0;
	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 2;
	tab[3] = 3;
	tab[4] = 4;
	size = 5;
	ft_rev_int_tab(tab, size);
	while (i < size)
	{
		printf("tab : %d\n", tab[i++]);
	}
}*/
