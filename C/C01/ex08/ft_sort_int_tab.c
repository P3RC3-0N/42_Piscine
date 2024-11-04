/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:21:07 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/03 15:24:47 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp_min;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		tmp_min = tab[i];
		while (j < size)
		{
			if (tmp_min > tab[j])
			{
				tmp_min = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp_min;
			}
			j++;
		}
		i++;
	}
}

/*
int	main(void)
{
	int tab[7] = {4, 5, 6, 3, 1, 3, 0};
	int i =0;
	
	ft_sort_int_tab(tab, -5);
	while (i<7)
	{
		printf("i : %d, tab : %d\n", i, tab[i]);
		i++;
	}
	return 0;
}*/
