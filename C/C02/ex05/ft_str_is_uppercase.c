/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:38:26 by thtricar          #+#    #+#             */
/*   Updated: 2024/06/30 19:46:11 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	nbr_c;

	nbr_c = 0;
	while (str[nbr_c] != '\0')
	{
		if (!(str[nbr_c] >= 65 && str[nbr_c] <= 90))
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
	printf("%d\n", ft_str_is_alpha(""));
	return (0);
}*/