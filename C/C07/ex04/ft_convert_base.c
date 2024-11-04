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
#include <stdlib.h>

int		ft_strc(char *str, char c, int nb_occ);
int		ft_strlen(char *str);
int		ft_nbrc(char *base, int nbr);
char	*ft_convert_base2(int nbr, char *base, char *str);

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

char	*ft_strcat(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (tmp);
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*new_nbr;
	int		signe;
	int		value;
	int		i;

	i = 0;
	signe = 1;
	value = 0;
	if (!(check_base(base_from) && (check_base(base_to))))
		return (0);
	while ((*nbr >= 9 && *nbr <= 13) || *nbr == 32)
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			signe *= -1;
		nbr++;
	}
	value = (ft_atoic(base_from, nbr) * signe);
	new_nbr = malloc(sizeof(char) * (ft_nbrc(base_to, value) + 1));
	if (new_nbr == NULL)
		return (free(new_nbr), NULL);
	new_nbr = ft_convert_base2(value, base_to, new_nbr);
	return (new_nbr);
}
