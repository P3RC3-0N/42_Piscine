/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vluo <vluo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:38:03 by vluo              #+#    #+#             */
/*   Updated: 2024/07/14 15:40:29 by vluo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

int	max_dict(struct s_dict *dict)
{
	struct s_dict	*temp;
	int				max;

	max = 0;
	temp = dict;
	while (temp != 0)
	{
		if (max < ft_strlen(temp -> key))
			max = ft_strlen(temp -> key);
		temp = temp -> next;
	}
	return (max);
}

void	*free_dict(struct s_dict *dict)
{
	if (dict -> next == 0)
	{
		free(dict -> key);
		free(dict -> value);
		free(dict);
		return (NULL);
	}
	free_dict(dict -> next);
	free(dict -> key);
	free(dict -> value);
	free(dict);
	return (NULL);
}

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i ++;
	}
	write(1, "\n", 1);
}

void	pr_dict(struct s_dict *dict)
{
	struct s_dict	*temp;

	temp = dict;
	while (temp != NULL)
	{
		putstr("key : ");
		putstr(temp -> key);
		write(1, "\n", 1);
		putstr("value : ");
		putstr(temp -> value);
		write (1, "\n", 1);
		temp = temp -> next;
	}
}
/*
int	main(void)
{
	struct s_dict *d;

	d = create_empty_dict();
	add_key(d, "hi", "lol");
	add_key(d, "k", "m");
	pr_dict(d);
	d = free_dict(d);
	pr_dict(d);
}
*/