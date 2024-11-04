/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:28:08 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/01 19:40:06 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_atoi(char *str)
{
	char	*tmp_str;
	int		signe;
	int		result;
	int		i;

	i = 0;
	tmp_str = str;
	signe = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57 && i < 9)
	{
		result *= 10;
		result += (str[i] - 48);
		str++;
	}
	str = tmp_str;
	return (result * signe);
}

/*
int	main(void)
{
	printf("%d\n", ft_atoi("   ---+--+1234ab567"));
	return (0);
}*/
