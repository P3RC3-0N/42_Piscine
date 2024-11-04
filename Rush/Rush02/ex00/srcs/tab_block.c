/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:33:07 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/14 16:33:10 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*free_tab(char **tab_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab_str[i] != NULL)
	{
		free(tab_str[i]);
		i++;
	}
	free(tab_str);
	return (NULL);
}

char	*init_tab_string(int size)
{
	int		i;
	char	*tab;

	tab = malloc(sizeof(char) * (size + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = '0';
		i++;
	}
	tab[size] = '\0';
	return (tab);
}

int	check_tab(char **tab_str, int index)
{
	if (tab_str[index] == NULL)
	{
		free_tab(tab_str);
		return (0);
	}
	return (1);
}

char	**init_all_tab(char **tab_str)
{
	int	i;

	i = 0;
	tab_str = malloc(sizeof(char *) * 5);
	if (tab_str == NULL)
		return (NULL);
	tab_str[0] = init_tab_string(1);
	if (!(check_tab(tab_str, 0)))
		return (NULL);
	tab_str[1] = init_tab_string(3);
	if (!(check_tab(tab_str, 1)))
		return (NULL);
	tab_str[2] = init_tab_string(2);
	if (!(check_tab(tab_str, 2)))
		return (NULL);
	tab_str[3] = init_tab_string(1);
	if (!(check_tab(tab_str, 3)))
		return (NULL);
	tab_str[4] = NULL;
	return (tab_str);
}

char	**fill_tab_str(char **tab_str, char *value, int size)
{
	int	i;

	i = 0;
	tab_str = init_all_tab(tab_str);
	if (tab_str == NULL)
		return (NULL);
	if (size % 3 == 0)
	{
		tab_str[0][0] = value[i];
		if (tab_str[0][0] != '0')
			tab_str[1][0] = '1';
		i++;
	}
	if (size % 3 == 2 || size % 3 == 0)
	{
		tab_str[2][0] = value[i];
		i++;
	}
	if (tab_str[2][0] != '1')
		tab_str[3][0] = value[i];
	else
		tab_str[2][1] = value[i];
	return (tab_str);
}
