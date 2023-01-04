/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:02:15 by carolina          #+#    #+#             */
/*   Updated: 2023/01/04 20:17:49 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFF_SIZE 7

char new_buffer_and_stash(char *joined_buffer, char type)
{
	size_t i;
	char *new_buffer;
	char *new_stash;

	i = 0;
	new_buffer = "";
	while (i <= ft_strlen(joined_buffer))
		i++; // length de joined_buffer
	i = 0;
	while (i <= BUFF_SIZE) //*buffer = ft_substr(joined_buffer, 0, BUFF_SIZE); //pose pb
	{
		new_buffer[i] = joined_buffer[i];
		i++;
	}
	new_stash = ft_substr(joined_buffer, BUFF_SIZE + 1, i);
	if (type == 'b')
		return (*new_buffer);
	if (type == 's')
		return (*new_stash);
	return(EXIT_FAILURE);
}

char is_new_line(char *buffer, char *stash)
{
	size_t i;
	size_t j;
	char *cut_buffer;
	char *stash_for_next_line;

	i = 0;
	while(buffer[i] != '\n')
		i++; //lenght jusqu'au \n
	cut_buffer = ft_substr(buffer, 0, i);
	printf("\nbuffer affiché :\n");
	ft_putstr(cut_buffer);
	stash_for_next_line = ft_strjoin(stash, ft_substr(buffer, i + 1, ft_strlen(buffer)));
	j = 0;
	while (stash_for_next_line[j])
		j++;
	stash_for_next_line[j] = '\0';
	return (*stash_for_next_line);
}

char no_new_line(char *buffer, char *stash)
{
	size_t i;
	char *cut_buffer;
	char *stash_for_next_line;

	cut_buffer = ft_substr(buffer, 0, BUFF_SIZE);
	printf("\nbuffer affiché :\n");
	ft_putstr(cut_buffer);
	stash_for_next_line = ft_strjoin(stash, ft_substr(buffer, BUFF_SIZE + 1, ft_strlen(buffer)));
	i = 0;
	while (stash_for_next_line[i])
		i++;
	stash_for_next_line[i] = '\0';
	return (*stash_for_next_line);
}

int main()
{
	int fd;
	//char *line;
	char buffer[BUFF_SIZE + 1]; //buffer = ft_calloc(BUFF_SIZE+ 1, sizeof(char));
	int bytes_read;
	size_t i;
	size_t j;
	char *stash;
	char *new_buffer;
	char *new_stash;
	char *joined_buffer;
	char *cut_buffer;
	char *stash_for_next_line;
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
			joined_buffer = ft_strjoin(stash, buffer) ;
			printf("\njoined_buffer : %s\n", new_buffer);
			new_buffer = new_buffer_and_stash(joined_buffer, 'b');
			printf("\nnew_buffer : %s\n", new_buffer);
			new_stash = new_buffer_and_stash(joined_buffer, 's');
			printf("\nnew_stash : %s\n", stash);
			if (ft_strchr(new_buffer, '\n') != NULL)
			{
				stash_for_next_line = is_new_line(new_buffer, new_stash); // ca va imprimer cut_buffer aussi
				printf("\nstash en mémoire %s\n", stash_for_next_line);
			}
			else // no new line
			{
				// couper jusqu a buff_size au lieu de \n
				stash_for_next_line = no_new_line(new_buffer, new_stash); // ca va imprimer cut_buffer aussi
				printf("\nstash en mémoire %s\n", stash_for_next_line);
			}
		}
		else
		{
			if (ft_strchr(buffer, '\n') != NULL)
			{
				i = 0;
				while(buffer[i] != '\n')
					i++;
				cut_buffer = ft_substr(buffer, 0, i);
				ft_putstr(cut_buffer);
				stash_for_next_line = ft_substr(buffer, i + 1, ft_strlen(buffer));
				j = 0;
				while (stash_for_next_line[j])
					j++;
				stash_for_next_line[j] = '\0';
			}
			else
			{
				printf("\nbuffer affiché :\n");
				ft_putstr(buffer);
			}

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
