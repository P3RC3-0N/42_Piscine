/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:50:45 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/01 15:33:20 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!to_find[i])
		return (str);
	while (str[i])
	{
		while (to_find[j] && str[i + j] == to_find[j])
		{		
			j++;
		}
		if (!to_find[j])
			return (&str[i]);
		j = 0;
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char	str[] = "salut a tou les tous amis";
	char	to_find[] = "tous";
	
	printf("mot : %s\n", ft_strstr(str, to_find));
	return 0;
}*/
