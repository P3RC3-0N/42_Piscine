/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:38:26 by thtricar          #+#    #+#             */
/*   Updated: 2024/06/30 20:49:33 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

char	*ft_strlowcase(char *str)
{
	int	nbr_c;

	nbr_c = 0;
	while (str[nbr_c] != '\0')
	{
		if (str[nbr_c] >= 65 && str[nbr_c] <= 90)
		{
			str[nbr_c] = str[nbr_c] + 32;
		}
		nbr_c++;
	}
	return (str);
}

/*
int	main(void)
{
	char	mot[] = "SALUTmec";
	char	*new;

	new = ft_strlowcase(mot);
	printf("%s\n", new);
	for (unsigned int i = 0; i < strlen(new); i++)
	{
		printf("%c\n", new[i]);
	}
	return (0);
}*/
