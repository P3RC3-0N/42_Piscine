/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:45:30 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/04 18:45:32 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1++ != *s2++)
			return (*--s1 - *--s2);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++ != '\0')
		count++;
	return (count);
}

void	ft_sort_char_matrix(int argc, char **argv)
{
	int		i;
	int		j;
	char	*min_word;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		min_word = argv[i];
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				min_word = argv[j];
				argv[j] = argv[i];
				argv[i] = min_word;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	ft_sort_char_matrix(argc, argv);
	i = 1;
	while (i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
