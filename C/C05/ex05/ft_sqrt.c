/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:53:51 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/04 17:53:53 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_sqrt(int nb)
{	
	int	i;

	if (nb < 0)
		return (0);
	else if (nb == 1)
		return (1);
	else
	{	
		i = 2;
		while (i * i < nb && i < 46341)
			i++;
	}
	if (i * i == nb)
		return (i);
	else
		return (0);
}

/*
int	main(void)
{
	printf("result : %d\n", ft_sqrt(49));
	return (0);
}*/
