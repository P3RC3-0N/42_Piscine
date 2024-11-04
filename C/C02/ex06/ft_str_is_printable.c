/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:38:26 by thtricar          #+#    #+#             */
/*   Updated: 2024/06/30 19:53:49 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	nbr_c;

	nbr_c = 0;
	while (str[nbr_c] != '\0')
	{
		if (!(str[nbr_c] >= 32 && str[nbr_c] <= 126))
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
	printf("%d\n", ft_str_is_printable(""));
	return (0);
}*/
