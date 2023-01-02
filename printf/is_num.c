/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:00:48 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/02 21:04:31 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_error1(char *base)
{
	int	i;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	is_error2(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (j < ft_strlen(base))
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(long long nbr, char *base)
{
	unsigned long long	n;
	int length;

	n = 0;
	length = 0; //ft_nbrlen
	if (is_error1(base) == 0 || is_error2(base) == 0)
		return (0);
	if (nbr < 0)
	{
		n = nbr * -1;
		ft_putchar('-');
		length++;
	}
	else
		n = nbr;
	if (n >= (unsigned long long)ft_strlen(base))
	{
		ft_putnbr_base(n / ft_strlen(base), base);
		length++;
	}
	ft_putchar(base[n % ft_strlen(base)]);
	length++;
	return(length); // si fx trop longue, utiliser ft_nbrlen a la place!!
}

int ft_is_num_int(int ptr, char type)
{
	char	*base;

	if (type == 'd' || type == 'i') // i : nb entier, d : nb decimal, u :décimal non signé
	{
		base = "0123456789";
		return(ft_putnbr_base(ptr, base));
	}
	return (0);
}

int ft_is_num_long(unsigned long long ptr, char type)
{
	char	*base;

	if (type == 'u')
	{
		base = "0123456789";
		return(ft_putnbr_base(ptr, base));
	}
	if (type == 'x')
	{
		base = "0123456789abcdef";
		return(ft_putnbr_base(ptr, base));
	}
	if (type == 'X')
	{
		base = "0123456789ABCDEF";
		return(ft_putnbr_base(ptr, base));
	}
	return (0);
}
