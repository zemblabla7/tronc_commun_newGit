/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:02:15 by carolina          #+#    #+#             */
/*   Updated: 2023/01/04 15:28:26 by casomarr         ###   ########.fr       */
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
	size_t i;
	char *stash;
	char *new_buffer;
	char *buffer_bis;

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
		buffer_bis = buffer;
		printf("buffer : %s", buffer_bis);
		buffer_bis[bytes_read + 1] = '\0';
		i = 0;
		if (stash != NULL)
		{
			printf("\ncondition 1\n");
			new_buffer = ft_strjoin(stash, buffer_bis) ;
			printf("\nstash + buffer joined : %s\n", new_buffer);
			i = 0;
			while (i <= ft_strlen(new_buffer))
				i++; // length de new_buffer
			buffer_bis = "";
			i = 0;
			while (i <= BUFF_SIZE) //*buffer = ft_substr(new_buffer, 0, BUFF_SIZE); //pose pb
			{
				buffer_bis[i] = new_buffer[i];
				i++;
			}
			printf("\nbuffer : %s\n", buffer_bis);
			stash = ft_substr(new_buffer, BUFF_SIZE + 1, i);
			printf("\nstash : %s\n", stash);
		}
		if (ft_strchr(buffer_bis, '\n') != NULL)
		{
			printf("\ncondition 2\n");
			i = 0;
			while(buffer_bis[i] != '\n')
				i++; //lenght jusqu'au \n
			stash = ft_substr(buffer_bis, i + 1, ft_strlen(buffer_bis)); // + ce que j'avais deja dans le stash!!!
			char *buffer1 = ft_substr(buffer_bis, 0, i);
			printf("\nbuffer affiché :\n");
			ft_putstr(buffer1);
			printf("\nstash en mémoire %s\n", stash);
		}
		else
		{
			printf("\ncondition 3\n");
			printf("\nbuffer affiché :\n");
			ft_putstr(buffer);
		}

		//printf("\nnb_of_bytes dans buffer : %li\n", ft_strlen(buffer));
		//printf("\nnb_of_bytes dans stash : %li\n\n", ft_strlen(stash));
		bytes_read = read(fd, buffer, BUFF_SIZE);
		printf("\nNext Buffer\n");
	}

	if (close(fd) == -1) // en checkant si = -1, ça execute la commande "close"
	{
		ft_putstr("close command failed\n");
		return (1);
	}
	return (0);
}
