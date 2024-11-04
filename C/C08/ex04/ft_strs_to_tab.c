/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:11:35 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/16 14:11:38 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++ != '\0')
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*dup_src;
	int		i;

	i = 0;
	dup_src = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dup_src == NULL)
		return (NULL);
	while (src[i])
	{
		dup_src[i] = src[i];
		i++;
	}
	dup_src[i] = '\0';
	return (dup_src);
}

void	*free_t_stock_str(t_stock_str *tab_struct, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(tab_struct[i].copy);
		i++;
	}
	free(tab_struct);
	return (NULL);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab_struct;

	i = 0;
	tab_struct = malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab_struct == NULL)
		return (free(tab_struct), NULL);
	while (i < ac)
	{
		tab_struct[i].size = ft_strlen(av[i]);
		tab_struct[i].str = av[i];
		tab_struct[i].copy = ft_strdup(av[i]);
		if (tab_struct[i].copy == NULL)
		{
			return (free_t_stock_str(tab_struct, i));
		}
		i++;
	}
	tab_struct[ac].str = NULL;
	return (tab_struct);
}
