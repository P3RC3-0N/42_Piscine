/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vluo <vluo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:30:45 by vluo              #+#    #+#             */
/*   Updated: 2024/07/14 19:58:38 by vluo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	add_keyval_from_input(char *str, struct s_dict *dict)
{
	char	*key;
	char	*value;

	key = get_key_from_input(str);
	if (ft_strcmp(key, "Dict Error") == 0)
	{
		putstr("Dict Error");
		free(str);
		return (0);
	}
	value = get_value_from_input(str);
	if (ft_strcmp(value, "Dict Error") == 0)
	{
		putstr("Dict Error");
		free(str);
		return (0);
	}
	add_key(dict, key, value);
	free(str);
	return (1);
}

char	*reaad(const char *file)
{
	int				fd;
	int				sz;
	char			*c;

	c = malloc(30000 * sizeof(char));
	if (c == 0)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	sz = read(fd, c, 30000);
	c[sz] = '\0';
	close(fd);
	return (c);
}

struct s_dict	*add_in_dict(struct s_dict *dict, char *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c[i] != '\0')
	{
		j = 0;
		while (c[i + j] != '\0' && c[i + j] != '\n')
			j ++;
		if (j >= 1)
		{
			if (add_keyval_from_input(ft_dup(c, i, i + j + 1), dict) == 0)
			{
				dict = free_dict(dict);
				return (0);
			}
		}
		i = i + j + 1;
	}
	return (dict);
}

struct s_dict	*create_dict(const char *file)
{
	char			*c;
	struct s_dict	*dict;

	c = reaad(file);
	if (c == 0)
		return (0);
	dict = create_empty_dict();
	if (dict == 0)
	{
		free(c);
		return (0);
	}
	dict = add_in_dict(dict, c);
	free(c);
	return (dict);
}

// int	main(void)
// {
// 	struct s_dict *d;

// 	d = create_dict("numbers.dict");
// 	free_dict(d);
// 	d = 0;
// }