/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:35:53 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/04 04:36:12 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return (s1[i] - s2[i]);
}

/*
int	main(void)
{
	printf("nb : %d\n", ft_strcmp("salut", "salut2"));
	printf("nb : %d\n", ft_strcmp("salut2", "salut"));
	printf("nb : %d\n", ft_strcmp("salut", "salut"));
	return (0);
}*/
