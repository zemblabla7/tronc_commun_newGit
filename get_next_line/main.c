/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina <carolina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:02:15 by carolina          #+#    #+#             */
/*   Updated: 2023/01/03 17:19:31 by carolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFF_SIZE 7

int main()
{
	int fd; 
	//char *line;
	char buffer[BUFF_SIZE + 1]; //buffer = ft_calloc(BUFF_SIZE+ 1, sizeof(char));
	int bytes_read;
	int i;
	char *stash;

	fd = open("test", O_RDONLY | O_CREAT);
	if (fd == -1)
	{
		ft_putstr("open command failed\n");
		return (1);
	}

	bytes_read = 0;
	bytes_read = read(fd, buffer, BUFF_SIZE);
	while (bytes_read > 0)
	{
		printf("buffer : %s", buffer);
		buffer[bytes_read + 1] = '\0';
		i = 0;
		if (stash != NULL)
		{
			char *new_buffer = ft_strjoin(stash, buffer) ;
			printf("\nstash + buffer joined : %s\n", new_buffer);
			*buffer = ft_substr(buffer, 0, i); //pose pb
			stash = ft_substr(buffer, i, BUFF_SIZE);
		}
		if (ft_strchr(buffer, '\n') != NULL)
		{
			while(buffer[i] != '\n')
				i++;
			stash = ft_substr(buffer, 0, i);
			printf("\nstash :\n");
			ft_putstr(stash);
			stash = ft_substr(buffer, i, BUFF_SIZE);
			printf("\nstash en mémoire %s\n", stash);
		}
		else
		{
			printf("\nbuffer :\n");
			ft_putstr(buffer);
		}
			
		//printf("\nnb_of_bytes dans buffer : %li\n", ft_strlen(buffer));
		//printf("\nnb_of_bytes dans stash : %li\n\n", ft_strlen(stash));
		bytes_read = read(fd, buffer, BUFF_SIZE);
	}
	
	if (close(fd) == -1) // en checkant si = -1, ça execute la commande "close"
	{
		ft_putstr("close command failed\n");
		return (1);
	}
	return (0);
}
