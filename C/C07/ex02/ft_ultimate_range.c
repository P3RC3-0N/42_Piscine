/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:13:35 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/04 20:13:37 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*tab;

	size = max - min;
	i = 0;
	if (size <= 0)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc(sizeof(int) * size);
	if (tab == NULL)
		return (-1);
	while (i < size)
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	return (max - min);
}

/*
int	main(void)
{
	int	i;
	int	**range;

	range = malloc(sizeof(int*) * 1);
	if (range == NULL)
		return -1;
	range[0] = malloc(sizeof(int) * 1);
	if (range[0] == NULL)
		return -1;
	printf("taille : %d\n", ft_ultimate_range(range, -2, -1));
	i = 0;
	while (i < -1 - 2)
	{
		printf("tab : [%d]\n", range[0][i]);
		i++;
	}
	return (0);
}*/
