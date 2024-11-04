/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vluo <vluo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:31:42 by vluo              #+#    #+#             */
/*   Updated: 2024/07/14 19:59:24 by vluo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*ft_d(char *str)
{
	char	*d;
	int		i;

	d = malloc(ft_strlen(str) + 1 * sizeof(char));
	if (d == 0)
		return (0);
	i = 0;
	while (i < ft_strlen(str))
	{
		d[i] = str[i];
		i ++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_dup(char *str, int start, int end)
{
	char	*dup;
	int		i;
	int		j;

	dup = malloc((end - start + 1) * sizeof(char));
	if (dup == 0)
		return (0);
	i = start;
	j = 0;
	while (i < end)
	{
		dup[j] = str[i];
		i ++;
		j ++;
	}
	dup[j] = '\0';
	return (dup);
}

char	*get_key_from_input(char *str)
{
	int	startnb;
	int	endnb;

	startnb = 0;
	while (str[startnb] && (str[startnb] == 32
			|| (str[startnb] >= 9 && str[startnb] <= 13)))
		startnb ++;
	endnb = startnb;
	if (str[startnb] == 43)
		endnb = startnb + 1;
	if (str[startnb] == 45)
		endnb = startnb + 1;
	while (str[endnb] >= 48 && str[endnb] <= 57)
		endnb ++;
	if (str[endnb] != 32 && str[endnb] != 58)
		return ("Dict Error");
	return (ft_dup(str, startnb, endnb));
}

int	endkey_frominput(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i ++;
	if (str[i] == 43 || str[i] == 45)
		i ++;
	while (str[i] >= 48 && str[i] <= 57)
		i ++;
	while (str[i] == 32)
		i ++;
	return (i);
}

char	*get_value_from_input(char *str)
{
	int	i;
	int	j;

	i = endkey_frominput(str);
	if (str[i] == 58)
		i ++;
	else
		return ("Dict Error");
	while (str[i] == 32)
		i ++;
	j = i;
	while (str[j] > 32 && str[j] <= 126 && str[j] != '\n' && str[j] != '\0')
		j ++;
	if (!(str[j] == '\n' || str[j] != '\0'))
		return ("Dict Error");
	return (ft_dup(str, i, j));
}
