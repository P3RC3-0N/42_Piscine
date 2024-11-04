/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:47:22 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/04 04:47:30 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	printf("nb : %d\n", ft_strncmp("sati", "satu", 3));
	printf("nb : %d\n", ft_strncmp("sa", "saturne", 5));
	printf("nb : %d\n", ft_strncmp("saturne", "sa", 5));
	printf("nb : %d\n", ft_strncmp("sa", "sa", 5));
	return (0);
}*/
