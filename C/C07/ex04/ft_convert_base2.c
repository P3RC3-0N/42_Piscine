/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:50:42 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/01 20:37:40 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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

int	ft_nbrc(char *base, int nbr)
{
	int				base_len;
	unsigned int	pow;
	int				count;
	unsigned int	nbr_u;

	if (nbr < 0)
		nbr_u = -nbr;
	else
		nbr_u = nbr;
	base_len = ft_strlen(base);
	pow = base_len;
	count = 0;
	while (nbr_u > pow)
	{
		pow *= base_len;
		count++;
	}
	return (count + 1);
}

void	ft_recursive_itoa_base(int nbr_u, unsigned int len_base,
							char *base, char *str)
{
	int	i;

	i = 0;
	if (!str[0] && nbr_u < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		nbr_u = -nbr_u;
	}
	if (nbr_u / len_base != 0)
	{
		ft_recursive_itoa_base(nbr_u / len_base, len_base, base, str);
		while (str[i])
			i++;
		str[i] = (base[nbr_u % len_base]);
		str[i + 1] = '\0';
	}
	else
	{
		while (str[i])
			i++;
		str[i] = (base[nbr_u % len_base]);
		str[i + 1] = '\0';
	}
}

char	*ft_convert_base2(int nbr, char *base_to, char *str)
{
	char			*tmp_base;
	int				no_unique;

	no_unique = 0;
	tmp_base = base_to;
	ft_recursive_itoa_base(nbr, ft_strlen(base_to), base_to, str);
	return (str);
}
