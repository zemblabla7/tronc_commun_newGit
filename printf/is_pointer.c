/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:41:45 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/02 16:21:47 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_is_pointer(void *ptr)
{
	unsigned long adress;
	char *base;
	char result[9];
	int i;

	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		return ;
	}
	adress = (unsigned long)ptr;
	base = "0123456789abcdef";
	i = 8; // 6 numeros + 0x
	while ((adress / 16) > 0)
	{
		result[i] = base[(adress % 16)];
		adress = adress / 16;
		i--;
	}
	result[i] = base[(adress % 16)];
	ft_putchar('0');
	ft_putchar('x');
	while(i < 9) // 6 numeros + 0x + \0
	{
		ft_putchar(result[i]);
		i++;
	}
}
