/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:06:11 by thtricar          #+#    #+#             */
/*   Updated: 2024/06/28 12:20:27 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;
	int	*p_div;
	int	*p_mod;

	a = 42;
	b = 24;
	p_div = &div;
	p_mod = &mod;
	ft_div_mod(a, b, p_div, p_mod);
	printf("div : %d, mod : %d", *p_div, *p_mod);
}*/
