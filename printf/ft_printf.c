/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina <carolina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:06:18 by casomarr          #+#    #+#             */
/*   Updated: 2022/12/30 22:39:18 by carolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include <stdarg.h> 
// # include <stdio.h>
// # include <unistd.h>
// # include <stdlib.h>

// # include "is_char.c"
// # include "is_num.c"

#include "libftprintf.h"

int ft_printf(const char *arg, ...) //attention prototype dans le sujet ne précise pas que le premier argument s'appelle arg!
{
	va_list ptr; // pointer on the first argument (therefore the const char *)
	va_start (ptr, arg); // pointer on the first argument, argument (on donne à const char * le nom "arg")
	int i;
	char type;

	i = 0;
	type = 0;
	while(arg[i])
	{
		while (arg[i] != '%' && arg[i] != '\0')
		{
			ft_putchar(arg[i]);
			i++;
		}
		if (arg[i] == '%')
			i++;
		if (arg[i] == 'c')
		{
			ft_putchar(va_arg(ptr, int));
			i++;
		}
		if (arg[i] == 's')
		{
			ft_putstr(va_arg(ptr, char *));
			i++;
		}	
		if (arg[i] == 'd' || arg[i] == 'i') 
		{
			type = arg[i];
			ft_is_num(va_arg(ptr, long long), type);
			i++;
		}
		if (arg[i] == 'x' || arg[i] == 'X' || arg[i] == 'u') 
		{
			type = arg[i];
			ft_is_num(va_arg(ptr, unsigned long long), type);
			i++;
		}
		//if (arg[i] == 'p')
			//???
		if (arg[i] == '%')
		{
			ft_putchar('%');
			while (arg[i] == '%')
			{
				ft_putchar('%');
				i++;
			}
		}
	}
	va_end (ptr);
}

int main()
{
	char *string = "linda";
	char caractere = 'L';
	int nb_entier = 1843;
	long long nb_decimal = 1843;
	int hexa_min = 1643;
	int hexa_maj = 1643;
	char *s1 = "linda";
	char *s2 = "cómo";
	char *s3 = "vas?";
	
	ft_printf("Hola %s\n", string);
	ft_printf("Hola %c\n", caractere);
	ft_printf("Hola %i\n", nb_entier);
	ft_printf("Hola %d\n", nb_decimal);
	ft_printf("Hola %x\n", hexa_min);
	ft_printf("Hola %X\n", hexa_maj);
	ft_printf("Hola %s %s %s\n", s1, s2, s3);
	ft_printf("Hola %%%\n"); 
	
	return 0;
}
