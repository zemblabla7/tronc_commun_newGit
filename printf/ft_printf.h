/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:42:05 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/02 20:58:52 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *arg, ...);
int	ft_format(int i, const char *arg, va_list ptr);
int	ft_strlen(char *str);
int	is_error1(char *base);
int	is_error2(char *base);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int ft_is_pointer(unsigned long long ptr, int trigger);
int	ft_putnbr_base(long long nbr, char *base);
int	ft_is_num_int(int ptr, char type);
int	ft_is_num_long(unsigned long long ptr, char type);
int ft_nbrlen(long long ptr, int base_len);

#endif
