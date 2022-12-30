/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina <carolina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:00:58 by casomarr          #+#    #+#             */
/*   Updated: 2022/12/30 21:27:23 by carolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//# include <stddef.h> //EFFACER

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

char	ft_is_c(int ptr)
{
	ft_putchar(ptr);
}

char	ft_is_s(char *ptr)
{
	ft_putstr(ptr);
}