/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:05:18 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/04 20:05:21 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++ != '\0')
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*dup_src;
	int		i;

	i = 0;
	dup_src = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dup_src == NULL)
		return (NULL);
	while (src[i])
	{
		dup_src[i] = src[i];
		i++;
	}
	dup_src[i] = '\0';
	return (dup_src);
}

/*
int	main(void)
{
	char	*src;

	src = malloc(sizeof(char) * 7);
	src = "bonjour";
	printf("changement : %s\n", ft_strdup(src));
	return (0);
}*/
