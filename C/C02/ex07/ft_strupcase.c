/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:38:26 by thtricar          #+#    #+#             */
/*   Updated: 2024/06/30 20:35:44 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

char	*ft_strupcase(char *str)
{
	int	nbr_c;

	nbr_c = 0;
	while (str[nbr_c] != '\0')
	{
		if (str[nbr_c] >= 97 && str[nbr_c] <= 122)
		{
			str[nbr_c] = str[nbr_c] - 32;
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

	new = ft_strupcase(mot);
	printf("%s\n", new);
	for (unsigned int i = 0; i < strlen(new); i++)
	{
		printf("%c\n", new[i]);
	}
	return (0);
}*/
