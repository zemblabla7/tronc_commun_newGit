/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:00:48 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/02 21:43:09 by casomarr         ###   ########.fr       */
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

	n = 0;
	if (is_error1(base) == 0 || is_error2(base) == 0)
		return (0);
	if (nbr < 0)
	{
		n = nbr * -1;
		ft_putchar('-');
	}
	else
		n = nbr;
	if (n >= (unsigned long long)ft_strlen(base))
		ft_putnbr_base(n / ft_strlen(base), base);
	ft_putchar(base[n % ft_strlen(base)]);
	return(ft_nbrlen(nbr, ft_strlen(base)));
}

int	ft_is_num_int(int ptr)
{
	return(ft_putnbr_base(ptr, "0123456789"));
}

int	ft_is_num_long(unsigned long long ptr, char type)
{
	if (type == 'u')
		return(ft_putnbr_base(ptr, "0123456789"));
	if (type == 'x')
		return(ft_putnbr_base(ptr, "0123456789abcdef"));
	if (type == 'X')
		return(ft_putnbr_base(ptr, "0123456789ABCDEF"));
	return (0);
}
