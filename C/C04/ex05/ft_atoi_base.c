/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 07:24:18 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/04 07:24:20 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strc(char *str, char c, int nb_occ)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{				
		if (str[i] == c)
		{
			count++;
		}
		if (count == nb_occ)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

int	check_base(char *base)
{
	int	no_unique;
	int	i;

	no_unique = 0;
	i = 0;
	if (!(ft_strlen(base) < 2 || ft_strc(base, '+', 1)
			|| ft_strc(base, '-', 1)))
	{
		while (base[i] && no_unique == 0)
		{
			no_unique += ft_strc(base, base[i], 2);
			if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
				no_unique += 1;
			i++;
		}
		if (no_unique == 0)
			return (1);
	}
	return (0);
}

int	ft_atoic(char *base, char *str)
{
	int	i;
	int	value;
	int	j;

	i = 0;
	value = 0;
	j = 0;
	while (ft_strc(base, str[j], 1))
	{
		value *= ft_strlen(base);
		while (str[j] != base[i])
			i++;
		value += i;
		j++;
		i = 0;
	}
	return (value);
}

int	ft_atoi_base(char *str, char *base)
{
	char	*tmp_str;
	int		signe;
	int		i;

	i = 0;
	tmp_str = str;
	signe = 1;
	if (!(check_base(base)))
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	return (ft_atoic(base, str) * signe);
}

/*
int	main(void)
{
	printf("test1 : %d\n", ft_atoi_base("   ---+--+2147483648", "0123456789"));
	return (0);
}*/
