/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtricar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:55:16 by thtricar          #+#    #+#             */
/*   Updated: 2024/06/28 12:02:25 by thtricar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
int	main(void)
{
	int	a;
	int	b;
	int	*p_a;
	int	*p_b;

	p_a = &a;
	p_b = &b;
	a = 42;
	b = 24;
	ft_swap(p_a, p_b);
	printf("a : %d, b : %d \n", *p_a, *p_b);
}*/
