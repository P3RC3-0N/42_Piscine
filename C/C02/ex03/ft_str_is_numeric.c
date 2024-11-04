/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:38:26 by thtricar          #+#    #+#             */
/*   Updated: 2024/06/30 19:39:56 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	nbr_c;

	nbr_c = 0;
	while (str[nbr_c] != '\0')
	{
		if (!(str[nbr_c] >= 48 && str[nbr_c] <= 57))
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
	printf("%d\n", ft_str_is_numeric("15"));
	return (0);
}*/
