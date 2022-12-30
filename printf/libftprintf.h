
#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include <stdarg.h> 
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int ft_printf(const char *arg, ...); // PAS LE BON PROTOTYPE
int	ft_strlen(char *str);
int	is_error1(char *base); //nécessaire? n'était pas dans libft.h
int is_error2(char *base); //nécessaire? n'était pas dans libft.h
void	ft_putchar(int c);
void	ft_putstr(char *s);
void    ft_putnbr_base(unsigned long long nbr, char *base);
void    ft_is_num(long long ptr, char type);

#endif