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

int	*ft_range(int min, int max)
{
	int	size;
	int	i;
	int	*tab;

	size = max - min;
	i = 0;
	if (size <= 0)
		return (NULL);
	else
	{
		tab = malloc(sizeof(int) * size);
		if (tab == NULL)
			return (NULL);
	}
	while (i < size)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}

/*
int	main(void)
{
	int	i;
	int	*tab;

	i = 0;
	tab = ft_range(25, 100);
	while (i < 100 - 25)
	{
		printf("tab : [%d]\n", tab[i]);
		i++;
	}
	return (0);
}*/
