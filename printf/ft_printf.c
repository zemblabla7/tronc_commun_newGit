/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina <carolina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:06:18 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/03 12:56:48 by carolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(int i, const char *arg, va_list ptr)
{
	char type;

	type = 0;
	if (arg[i + 1] == 'c')
		return(ft_putchar(va_arg(ptr, int)));
	else if (arg[i + 1] == 's')
		return(ft_putstr(va_arg(ptr, char *)));
	else if (arg[i + 1] == 'd' || arg[i + 1] == 'i')
		return(ft_is_num_int(va_arg(ptr, int)));
	else if (arg[i + 1] == 'x' || arg[i + 1] == 'X' || arg[i + 1] == 'u')
		return(ft_is_num_long(va_arg(ptr, long long), arg[i + 1]));
	else if (arg[i + 1] == 'p')
		return(ft_is_pointer(va_arg(ptr, unsigned long long), 1));
	else if (arg[i + 1] == '%')
		return(ft_putchar('%'));
	else
	{
		ft_putchar('%');
		ft_putchar(arg[i + 1]);
		return(2);
	}
}

int	ft_printf(const char *arg, ...)
{
	va_list ptr;
	va_start (ptr, arg);
	int i;
	int length;

	i = 0;
	length = 0;
	while(arg[i])
	{
		if (arg[i] != '%')
			length += ft_putchar(arg[i++]);
		else
		{
			length += ft_format(i, arg, ptr);
			i += 2;
		}
	}
	va_end(ptr);
	return (length);
}
