/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:54:39 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/08 18:01:24 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++ != '\0')
		count++;
	return (count);
}

int	ft_global_strlen(char **strs, int size)
{
	int	i;
	int	j;
	int	global_length;

	i = 0;
	j = 0;
	global_length = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			global_length++;
			j++;
		}
		j = 0;
		i++;
	}
	return (global_length);
}

char	*ft_fillstr(char **strs, char *str, char *sep, int size)
{
	int	j;
	int	k;
	int	sep_size;
	int	i;

	j = 0;
	k = 0;
	i = 0;
	sep_size = ft_strlen(sep);
	while (i < size)
	{
		while (strs[i][j])
			str[k++] = strs[i][j++];
		j = 0;
		while (j < sep_size && i != size - 1)
			str[k++] = sep[j++];
		j = 0;
		i++;
	}
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		global_length;
	int		sep_size;
	int		i;

	global_length = 0;
	i = 0;
	if (size == 0)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	else
	{
		sep_size = ft_strlen(sep);
		global_length = ft_global_strlen(strs, size) + (sep_size * (size - 1));
		str = malloc(sizeof(char) * (global_length + 1));
		str = ft_fillstr(strs, str, sep, size);
		str[global_length] = '\0';
		return (str);
	}
}

/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("chaine : %d\n", ft_strjoin(0, argv, "")[0]);
}*/
