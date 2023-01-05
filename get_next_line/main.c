/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina <carolina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:02:15 by carolina          #+#    #+#             */
/*   Updated: 2023/01/05 14:43:05 by carolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFF_SIZE 7

// char *new_buffer_and_stash(char *joined_buffer, char type)
// {
// 	size_t i;
// 	char *new_buffer;
// 	char *new_stash;

// 	new_stash = ft_substr(joined_buffer, BUFF_SIZE + 1, (ft_strlen(joined_buffer) - BUFF_SIZE + 1));
// 	new_buffer = ft_substr(joined_buffer, 0, BUFF_SIZE);
// 	if (type == 'b')
// 		return (new_buffer);
// 	if (type == 's')
// 		return (new_stash);
// 	return(NULL);
// }

char *is_new_line(char *buffer, char *stash)
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
	stash_for_next_line = ft_strjoin(stash, ft_substr(buffer, i + 1, (ft_strlen(buffer) - (i + 1))));
	j = 0;
	while (stash_for_next_line[j])
		j++;
	stash_for_next_line[j] = '\0';
	return (stash_for_next_line);
}

char *no_new_line(char *buffer, char *stash) // si j'utilise strlcpy et strlcat un des params est le nb de bytes
{
	size_t i;
	char *cut_buffer;
	char *stash_for_next_line;

	cut_buffer = ft_substr(buffer, 0, BUFF_SIZE);
	printf("\nbuffer affiché :\n");
	ft_putstr(cut_buffer);
	stash_for_next_line = ft_strjoin(stash, ft_substr(buffer, BUFF_SIZE + 1, (ft_strlen(buffer) - (BUFF_SIZE + 1))));
	i = 0;
	while (stash_for_next_line[i])
		i++;
	stash_for_next_line[i] = '\0';
	return (stash_for_next_line);
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
		printf("buffer_bis : %s", buffer_bis);
		buffer_bis[bytes_read + 1] = '\0';
		i = 0;
		if (stash_for_next_line != NULL)
		{
			joined_buffer = ft_strjoin((char *)stash_for_next_line, (char *)buffer_bis);
			printf("\njoined_buffer : %s\n", joined_buffer);
			new_buffer = ft_substr(joined_buffer, 0, BUFF_SIZE);
			printf("\nnew_buffer : %s\n", new_buffer);
			new_stash = ft_substr(joined_buffer, BUFF_SIZE + 1, (ft_strlen(joined_buffer) - BUFF_SIZE + 1));
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
			if (ft_strchr(buffer_bis, '\n') != NULL)
			{
				i = 0;
				while(buffer_bis[i] != '\n')
					i++;
				cut_buffer = ft_substr(buffer, 0, i);
				printf("\ncut_buffer: %s", cut_buffer);
				ft_putstr(cut_buffer);
				stash_for_next_line = ft_substr(buffer_bis, i + 1, (ft_strlen(buffer_bis) - (i + 1)));
				j = 0;
				while (stash_for_next_line[j])
					j++;
				stash_for_next_line[j] = '\0';
				printf("\nstash for next line: %s", stash_for_next_line);
			}
			else
			{
				printf("\nbuffer affiché :\n");
				ft_putstr(buffer_bis);
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
