/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:15:16 by thtricar          #+#    #+#             */
/*   Updated: 2024/07/17 16:15:18 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR
# define FT_STOCK_STR

#include <unistd.h>
#include <stdlib.h>
//#include <stdio.h>

typedef struct s_stock_str
{
	int	size;
	char	*str;
	char	*copy;
}		t_stock_str;

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

#endif
