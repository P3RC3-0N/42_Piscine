/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:06:18 by thtricar          #+#    #+#             */
/*   Updated: 2024/06/30 19:36:55 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	nbr_c;

	nbr_c = 0;
	while (str[nbr_c] != '\0')
	{
		if (!((str[nbr_c] >= 97 && str[nbr_c] <= 122)
				|| (str[nbr_c] >= 65 && str[nbr_c] <= 90)))
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
	printf("%d\n", ft_str_is_alpha("15salut"));
	return (0);
}*/
