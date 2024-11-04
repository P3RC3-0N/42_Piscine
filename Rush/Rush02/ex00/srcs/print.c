/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:20:59 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/13 16:21:13 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_string(struct s_str *string)
{
	struct s_str	*temp_str;

	temp_str = string;
	while (temp_str -> next != NULL)
	{
		ft_putstr(temp_str -> str);
		ft_putchar(' ');
		temp_str = temp_str -> next;
	}
	ft_putstr(temp_str -> str);
}

int	print_0(struct	s_dict *dict, struct	s_str *string, char *tmp_value)
{
	int	result;

	result = 1;
	if (!ft_strcmp(tmp_value, "0"))
	{
		result = add_str("0", dict, string);
		if (result == 0)
			return (0);
		tmp_value++;
	}
	return (1);
}

int	print_dict(char *value, struct	s_dict *dict)
{
	int				length;
	char			*tmp_value;
	struct s_str	*string;

	string = create_empty_str();
	if (string == NULL)
		return (0);
	tmp_value = good_value(value);
	print_0(dict, string, tmp_value);
	while (ft_strlen(tmp_value) != 0)
	{
		length = ft_strlen(tmp_value);
		if (!(print_block(tmp_value, dict, string, length)))
			return (0);
		if (length % 3 != 0)
			tmp_value += (length % 3);
		else
			tmp_value += 3;
	}
	print_string(string);
	free_str(string);
	return (1);
}

void	print_error(char *value, struct	s_dict *dict, int error)
{
	int	result;

	result = 1;
	if (error == 0)
	{
		result = print_dict(value, dict);
		if (result == 0)
			ft_putstr("Dict Error\n");
	}
	else if (error == 1)
	{
		ft_putstr("Error\n");
	}
	else
	{
		ft_putstr("Dict Error\n");
	}
}
