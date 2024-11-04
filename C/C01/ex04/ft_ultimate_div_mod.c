/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:06:11 by thtricar          #+#    #+#             */
/*   Updated: 2024/06/28 12:38:27 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{	
	int	div;

	div = *a / *b;
	*b = *a % *b;
	*a = div;
}

/*
int	main(void)
{
	int	a;
	int	b;
	int	*p_a;
	int	*p_b;

	a = 42;
	b = 24;
	p_a = &a;
	p_b = &b;
	ft_ultimate_div_mod(p_a, p_b);
	printf("div : %d, mod : %d", *p_a, *p_b);
}*/
