/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vluo <vluo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:07:30 by vluo              #+#    #+#             */
/*   Updated: 2024/07/14 18:18:06 by vluo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_allnb(char *value)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if (!(value[i] >= 48 && value[i] <= 57))
			return (0);
		i ++;
	}
	return (1);
}

int	canwrite(char *value, struct s_dict *dict)
{
	if (max_dict(dict) % 3 == 0)
		return (max_dict(dict) >= ft_strlen(value));
	return (max_dict(dict) - (max_dict(dict) % 3) + 3 >= ft_strlen(value));
}

int	main(int argc, char **argv)
{
	struct s_dict	*d;

	if (argc == 3)
	{
		d = create_dict(argv[1]);
		if (d == 0)
			return (0);
		if (is_allnb(argv[2]) == 1 && canwrite(argv[2], d))
			print_error(argv[2], d, 0);
		else
			ft_putstr("Dict Error");
		free_dict(d);
	}
	if (argc == 2)
	{
		d = create_dict("numbers.dict");
		if (d == 0)
			return (0);
		if (is_allnb(argv[1]) == 1 && canwrite(argv[1], d))
			print_error(argv[1], d, 0);
		else
			ft_putstr("Dict Error");
		free_dict(d);
	}
	return (0);
}
