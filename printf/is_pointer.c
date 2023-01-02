/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:41:45 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/02 21:02:06 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_nbrlen(long long ptr, int base_len) // si jamais j utilise cette fonction avec is_num, rajouter une condition si nb negatif
{
	int i;

	i = 0;
	if (ptr == 0)
		return (1);
	while (ptr > 0)
	{
		ptr = ptr / base_len;
		i++;
	}
	return (i);
}

int ft_is_pointer(unsigned long long ptr, int trigger)
{
	// unsigned long adress;
	// char *base;
	// char result[9];
	// int i;

	// if (ptr == NULL)
	// {
	// 	ft_putstr("(nil)");
	// 	return (5);
	// }
	// adress = (unsigned long)ptr;
	// base = "0123456789abcdef";
	// i = 8; // 6 numeros + 0x
	// while ((adress / 16) > 0)
	// {
	// 	result[i] = base[(adress % 16)];
	// 	adress = adress / 16;
	// 	i--;
	// }
	// result[i] = base[(adress % 16)];
	// ft_putchar('0');
	// ft_putchar('x');
	// while(i < 9) // 6 numeros + 0x + \0
	// {
	// 	ft_putchar(result[i]);
	// 	i++;
	// }
	// return(ft_nbrlen(ptr, 16) + 2);

	char * base;
	int length;

	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	base = "0123456789abcdef";
	length = ft_nbrlen(ptr, 16);
	if (trigger == 1)
		ft_putstr("0x");
	if (ptr > 15)
		ft_is_pointer((ptr / 16), 0);
	ft_putchar(base[ptr % 16]);
	return(ft_nbrlen(ptr, 16) + 2);
}
