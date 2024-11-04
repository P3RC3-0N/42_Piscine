/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:34:02 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/14 19:34:04 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	print_good_block(struct	s_dict *dict,
		struct	s_str *string, char **tab_str, int i)
{
	int	result;

	if (i == 2 && tab_str[i][0] == '1')
	{
		result = add_str(tab_str[i], dict, string);
		if (result == 0)
		{
			free_tab(tab_str);
			return (0);
		}
		i++;
	}
	else if (tab_str[i][0] != '0')
	{
		result = add_str(tab_str[i], dict, string);
		if (result == 0)
		{
			free_tab(tab_str);
			return (0);
		}
	}
	return (1);
}

int	print_greatness(struct	s_dict *dict, struct	s_str *string, int size)
{
	char	*greatness;
	int		greatness_size;
	int		result;

	result = 1;
	if (size % 3 == 0)
		greatness_size = size - 3 + 1;
	else
		greatness_size = size - (size % 3) + 1;
	greatness = NULL;
	greatness = init_tab_string(greatness_size);
	if (greatness == NULL)
	{
		free_str(string);
		return (0);
	}
	greatness[0] = '1';
	if (greatness_size > 1)
	{
		result = add_str(greatness, dict, string);
		if (result == 0)
			return (0);
	}
	free(greatness);
	return (1);
}

int	print_good_greatness(struct	s_dict *dict,
		struct	s_str *string, int size, char **tab_str)
{
	int	result;

	if (!(tab_str[0][0] == '0' && tab_str[2][0] == '0' && tab_str[3][0] == '0'))
	{
		result = print_greatness(dict, string, size);
		if (result == 0)
		{
			free_tab(tab_str);
			return (0);
		}
	}
	return (1);
}

int	print_block(char *value, struct	s_dict *dict,
		struct	s_str *string, int size)
{
	char	**tab_str;
	int		i;

	i = 0;
	tab_str = NULL;
	tab_str = fill_tab_str(tab_str, value, size);
	if (tab_str == NULL)
	{
		free_str(string);
		return (0);
	}
	while (tab_str[i] != NULL)
	{
		if (!(print_good_block(dict, string, tab_str, i)))
			return (0);
		i++;
	}
	if (!(print_good_greatness(dict, string, size, tab_str)))
		return (0);
	free_tab(tab_str);
	return (1);
}
