/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:31:23 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/14 16:31:28 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*free_str(struct	s_str *string)
{
	if (string -> next == 0)
	{
		free(string -> str);
		free(string);
		return (NULL);
	}
	free_str(string -> next);
	free(string -> str);
	free(string);
	return (NULL);
}

struct s_str	*create_empty_str(void)
{
	struct s_str	*res;

	res = malloc(sizeof(struct s_str));
	if (res == 0)
		return (0);
	res -> str = 0;
	res -> next = 0;
	return (res);
}

void	add_new_str(struct	s_str *string, struct	s_str *new_str)
{
	struct s_str	*temp_str;

	temp_str = string;
	if (temp_str -> str == NULL)
	{
		string -> str = ft_d(new_str -> str);
		string -> next = new_str -> next;
	}
	else
	{
		while (temp_str -> next != NULL)
		{	
			temp_str = temp_str -> next;
		}
		temp_str -> next = new_str;
	}
}

int	add_str(char *str, struct	s_dict *dict, struct	s_str *string)
{
	struct s_dict	*temp_dict;
	struct s_str	*new_str;

	temp_dict = dict;
	new_str = malloc(sizeof(struct s_str));
	if (new_str == NULL)
	{
		free_str(string);
		return (0);
	}
	while (temp_dict != NULL)
	{
		if (!ft_strcmp(temp_dict -> key, str))
		{
			new_str -> str = ft_d(temp_dict -> value);
			new_str -> next = NULL;
			break ;
		}
		temp_dict = temp_dict -> next;
	}
	add_new_str(string, new_str);
	return (1);
}
