/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:16:08 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/03 21:16:12 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

int	ft_c_is_alpha(char c)
{
	int	nbr_c;

	nbr_c = 0;
	if (!((c >= 97 && c <= 122) || (c >= 65 && c <= 90)))
	{
		return (0);
	}
	return (1);
}

int	ft_c_is_numeric(char c)
{
	int	nbr_c;

	nbr_c = 0;
	if (!(c >= 48 && c <= 57))
	{
		return (0);
	}
	return (1);
}

char	*ft_strlowcase(char *str)
{
	int	nbr_c;

	nbr_c = 0;
	while (str[nbr_c] != '\0')
	{
		if (str[nbr_c] >= 65 && str[nbr_c] <= 90)
		{
			str[nbr_c] = str[nbr_c] + 32;
		}
		nbr_c++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	nbr_c;

	nbr_c = 0;
	ft_strlowcase(str);
	while (str[nbr_c] != '\0')
	{
		if (ft_c_is_alpha(str[nbr_c]))
		{
			if (nbr_c > 0)
			{
				if (!(ft_c_is_alpha(str[nbr_c - 1])
						|| ft_c_is_numeric(str[nbr_c - 1])))
				{
					str[nbr_c] = str[nbr_c] - 32;
				}
			}
			else
			{
				str[nbr_c] = str[nbr_c] - 32;
			}
		}
		nbr_c++;
	}
	return (str);
}

/*
int	main(void)
{
	char	mot[] = "salut, comMent tu vas ? 42mots quarante-deux; cinquante+et+un";
	char	*new;

	new = ft_strcapitalize(mot);
	printf("%s\n", new);
	for (unsigned int i = 0; i < strlen(new); i++)
	{
		printf("%c\n", new[i]);
	}
	return (0);
}*/
