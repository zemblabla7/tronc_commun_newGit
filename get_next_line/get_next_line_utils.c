/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:02:30 by carolina          #+#    #+#             */
/*   Updated: 2023/01/04 15:22:41 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
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

void	ft_putnbr(int n)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr = n * -1;
		ft_putchar('-');
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10 + 48));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*new_str;

	if (len < 0 || s == NULL)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		new_str = malloc(sizeof(char) * 1);
		if (new_str == NULL)
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	new_str = malloc(sizeof(char) * len + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < len && ((char *)s)[start] != '\0')
	{
		new_str[i++] = ((char *)s)[start++];
	}
	new_str[i] = '\0';
	return (new_str);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 && size == 0)
		return (malloc(0));
	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		ft_strlen_total;
	char	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ft_strlen_total = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc((sizeof(char)) * (ft_strlen_total + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}
