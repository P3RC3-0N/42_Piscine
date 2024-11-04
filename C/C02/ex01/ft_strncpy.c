/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:19:00 by thtricar          #+#    #+#             */
/*   Updated: 2024/06/30 18:02:04 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i++] = '\0';
	}
	return (dest);
}

/*
int	main(void)
{
	char	dest[] = "salut";
	char	src[] = "bonjour";
	char	*new;
	
	new = ft_strncpy(dest, src, 7);
	printf("new : %s\n", new);
	printf("ft : %s\n", strncpy(dest, src, 3));
	return (0);
}*/
