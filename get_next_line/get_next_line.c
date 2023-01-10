/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:13:43 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/10 18:05:44 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*cut(char *big, char variable)
{
	size_t	i;
	char	*to_print;
	char	*in_memory;

	i = 0;
	while ((big[i] != '\n' || big[i] != '\0') && (i + 1) < BUFF_SIZE)
		i++;
	i += 1;
	if (i < BUFF_SIZE)
		in_memory = ft_substr(big, i, (ft_strlen(big) - i));
	else
		in_memory = NULL;
	to_print = ft_substr(big, 0, i);
	if (variable == 'm')
	{
		free(to_print);
		return (in_memory);
	}
	else
		return (to_print);
}

static char	*read(int bytes_read, char *buffer, char *to_print, char *in_memory)
{
	if (bytes_read > 0)
	{
		if (in_memory != NULL)
			buffer = ft_strjoin((char *)in_memory, (char *)buffer);
		to_print = cut(buffer, 'p');
		in_memory = cut(buffer, 'm');
	}
	else
	{
		if (in_memory == NULL)
		{
			free(buffer);
			return (NULL);
		}
		else
		{
			to_print = cut(in_memory, 'p');
			in_memory = cut(in_memory, 'm');
		}
	}
	free(buffer);
	return (to_print);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*buffer;
	static char	*to_print;
	static char	*in_memory;

	in_memory = NULL;
	to_print = NULL;
	if (fd == -1 || BUFF_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFF_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFF_SIZE);
	if (bytes_read == -1)
	{
		free (buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (read(bytes_read, buffer, to_print, in_memory));
}
