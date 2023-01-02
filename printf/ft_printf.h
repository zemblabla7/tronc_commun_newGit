/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:42:05 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/02 17:27:16 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *arg, ...); // PAS LE BON PROTOTYPE
int	ft_format(int i, const char *arg, va_list ptr);
int	ft_strlen(char *str);
int	is_error1(char *base);
int	is_error2(char *base);
void	ft_putchar(int c);
void	ft_putstr(char *s);
void	ft_putnbr_base(long long nbr, char *base);
void	ft_is_num_int(int ptr, char type);
void	ft_is_num_long(long long ptr, char type);
void	ft_is_pointer(void *ptr);

#endif
