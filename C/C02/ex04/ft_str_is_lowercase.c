/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:38:26 by thtricar          #+#    #+#             */
/*   Updated: 2024/06/30 19:52:31 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	nbr_c;

	nbr_c = 0;
	while (str[nbr_c] != '\0')
	{
		if (!(str[nbr_c] >= 97 && str[nbr_c] <= 122))
		{
			return (0);
		}
		nbr_c++;
	}
	return (1);
}

/*
int	main(void)
{
	printf("%d\n", ft_str_is_lowercase("15"));
	return (0);
}*/
