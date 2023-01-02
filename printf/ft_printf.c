/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:06:18 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/02 21:47:31 by casomarr         ###   ########.fr       */
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

int	ft_printf(const char *arg, ...) //attention prototype dans le sujet ne précise pas que le premier argument s'appelle arg!
{
	va_list ptr; // pointer on the first argument (therefore the const char *)
	va_start (ptr, arg); // pointer on the first argument, argument (on donne à const char * le nom "arg")
	int i;
	int length;

	i = 0;
	length = 0;
	while(arg[i])
	{
		// if (arg[i] == '%' && arg[i + 1] != '\0')
		// {
		// 	ft_format(i, arg, ptr);
		// 	length += ft_format(i, arg, ptr);
		// 	i++;
		// }
		// else
		// {
		// 	if (arg[i] == '%' && arg[i + 1] == '\0' )
		// 		break;
		// 	length += ft_putchar(arg[i]);
		// }
		// i++;

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

// int main()
// {
// 	//char *string = "linda";
// 	// char caractere = 'L';
// 	// int nb_entier = 1843;
// 	// long long nb_decimal = 1843;
// 	// int hexa_min = 1643;
// 	// int hexa_maj = 1643;
// 	// char *s1 = "linda";
// 	// char *s2 = "cómo";
// 	// char *s3 = "vas?";
// 	//char *p = "Hola";
// 	//char *p;

// 	//ft_printf("Hola %s\n", string);
// 	// ft_printf("Hola %c\n", caractere);
// 	// ft_printf("Hola %i\n", nb_entier);
// 	// ft_printf("Hola %d\n", nb_decimal);
// 	// ft_printf("Hola %x\n", hexa_min);
// 	// ft_printf("Hola %X\n", hexa_maj);
// 	// ft_printf("Hola %s %s %s\n", s1, s2, s3);
// 	// ft_printf("Hola %%%\n");
// 	//ft_printf("ft_printf0 : %p\n", p);
// 	//printf("printf : %p\n", p);

// 	// printf ("(%i)\n", printf("Helia"));
// 	// ft_printf ("(%i)\n", ft_printf("Helia"));

// 	// int i = -1;
// 	// ft_printf("%d\n", i);

// 	//ft_printf("(%i)\n", ft_printf("hola"));

// 	//int num = 64;
// 	//ft_printf("(%i)\n", ft_printf("64"));

// 	//ft_printf("(%i)\n", ft_printf("this is a test"));

// 	// ft_printf("%c", 'a');
// 	// printf("\n%c", 'a');

// 	ft_printf("%s", "");


// 	return (0);
// }

// int main ()
// {
// 	//ft_printf("This %p is even stranger\n", (void *)-1);
// 	ft_printf("(%i)", ft_printf("This %p is even stranger\n", (void *)-1));
// 	return 0;
// }
