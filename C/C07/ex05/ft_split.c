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

int	ft_strc(char *str, char c)
{
	char	*tmp_str;
	int		count;

	count = 0;
	tmp_str = str;
	while (*tmp_str)
	{				
		if (*tmp_str == c)
		{
			return (1);
		}
		tmp_str++;
	}
	return (0);
}

int	ft_strlen_charset(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0' && !ft_strc(charset, str[i]))
	{
		count++;
		i++;
	}
	return (count);
}

int	ft_nb_words(char *str, char *to_find)
{
	unsigned int	nb_sep;
	unsigned int	nb_word;
	unsigned int	i;

	i = 0;
	nb_sep = 1;
	nb_word = 0;
	while (str[i])
	{
		if (ft_strc(to_find, str[i]))
			nb_sep = 1;
		else
		{
			if (nb_sep == 1)
				nb_word++;
			nb_sep = 0;
		}
		i++;
	}
	return (nb_word);
}

void	fill_strs(char *strs, char *str, char *charset, int *k)
{
	int	j;

	j = 0;
	while (!ft_strc(charset, str[*k]) && str[*k])
	{
		strs[j++] = str[(*k)++];
	}
	strs[j] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		k;

	strs = malloc(sizeof(char *) * (ft_nb_words(str, charset) + 1));
	if (strs == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (i < ft_nb_words(str, charset))
	{
		while (ft_strc(charset, str[k]))
			k++;
		strs[i] = malloc(sizeof(char) * (ft_strlen_charset(&str[k],
						charset) + 1));
		if (strs[i] == NULL)
			return (NULL);
		fill_strs(strs[i], str, charset, &k);
		i++;
	}
	strs[ft_nb_words(str, charset)] = NULL;
	return (strs);
}

/*
int	main(int argc, char **argv)
{
	char	**strs;
	int	i;
	
	(void)argc;	
	i = 0;
	//printf("nb : %d\n", ft_nb_words(str, charset));
	strs = ft_split(argv[1], argv[2]);
	while (i < ft_nb_words(argv[1], argv[2]) + 1)
	{
		i++;
	}
}*/
