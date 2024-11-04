/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vluo <vluo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:33:58 by vluo              #+#    #+#             */
/*   Updated: 2024/07/14 18:28:23 by vluo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>
#include <stdio.h>

struct s_dict	*create_empty_dict(void)
{
	struct s_dict	*res;

	res = malloc(sizeof(struct s_dict));
	if (res == 0)
		return (0);
	res -> key = 0;
	res -> value = 0;
	res -> next = 0;
	return (res);
}

void	add_key(struct s_dict *dict, char *key, char *value)
{
	struct s_dict	*temp;
	struct s_dict	*new;

	if (dict -> key == 0)
	{
		dict -> key = key;
		dict -> value = value;
		dict -> next = 0;
		return ;
	}
	new = malloc(sizeof(struct s_dict));
	if (new == 0)
		return ;
	temp = dict;
	while (temp -> next != NULL)
		temp = temp -> next;
	new -> key = key;
	new -> value = value;
	new -> next = NULL;
	temp -> next = new;
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i ++;
	}
	return (0);
}

char	*get_value(struct s_dict *dict, char *key)
{
	struct s_dict	*temp;

	temp = dict;
	while (temp != 0)
	{
		if (ft_strcmp(temp -> key, key) == 0)
			return (temp -> value);
	}
	return (0);
}

// int	main(void)
// {
// 	struct s_dict *d;

// 	d = create_empty_dict();
// 	add_key(d, "1", "one");
// 	add_key(d, "2", "two");
// 	pr_dict(d);
// }
