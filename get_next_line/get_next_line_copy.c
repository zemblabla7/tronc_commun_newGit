/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:13:43 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/10 19:38:14 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*cut(char *big, char variable)
{
	size_t	i;
	char	*print;
	char	*memory;

	i = 0;
	//while ((big[i] != '\n' || big[i] != '\0') && (i + 1) < BUFF_SIZE)
	while (big[i] != '\n')
		i++;
	printf ("\n (%zu) \n)", i);
	i += 1;
	if (i < BUFF_SIZE)
		memory = ft_substr(big, i, (ft_strlen(big) - i));
	else
		memory = NULL;
	print = ft_substr(big, 0, i);
	if (variable == 'm')
	{
		free(print);
		printf("\n memory : %s \n", memory);
		return (memory);
	}
	else
		return (print);
}

static char	*gnl_read(int bytes_read, char *buffer, char *in_memory, int i)
{
	char		*to_print;

	to_print = NULL;
	printf("\n in memory : %s \n", in_memory);
	if (bytes_read > 0)
	{
		if (in_memory != NULL)
			buffer = ft_strjoin((char *)in_memory, (char *)buffer);
		printf("\n buffer : %s \n", buffer);
		to_print = cut(buffer, 'p');
		in_memory = cut(buffer, 'm');
		printf("\n in memory : %s \n", in_memory);
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
			printf("\n in_memory = %s \n", in_memory);
		}
	}
	printf("\nto_print : %s \n", to_print);
	free(buffer);
	if (i == 1)
		return (to_print);
	else
		return(in_memory);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*buffer;
	static char	*in_memory;

	in_memory = NULL;
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
	in_memory = gnl_read(bytes_read, buffer, in_memory, 0);
	printf("\n in memory : %s \n", in_memory);
	return (gnl_read(bytes_read, buffer, in_memory, 1));
}
