/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sans_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina <carolina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:02:15 by carolina          #+#    #+#             */
/*   Updated: 2023/01/05 17:03:33 by carolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFF_SIZE 7

char *is_new_line(char *buffer, char *stash)
{
	size_t i;
	char *cut_buffer;
	char *stash_for_next_line;

	i = 0;
	while(buffer[i] != '\n') // ou utiliser strchr?
		i++; //lenght jusqu'au \n
	cut_buffer = ft_substr(buffer, 0, i + 1);
	ft_putstr(cut_buffer);
	stash_for_next_line = ft_strjoin(stash, ft_substr(buffer, i + 2, (ft_strlen(buffer) - (i + 2)))); // car [i] est un de mois que i
	return (stash_for_next_line);
}

char *no_new_line(char *buffer, char *stash) // si j'utilise strlcpy et strlcat un des params est le nb de bytes
{
	char *cut_buffer;
	char *stash_for_next_line;

	cut_buffer = ft_substr(buffer, 0, BUFF_SIZE + 1);
	ft_putstr(cut_buffer);
	stash_for_next_line = ft_strjoin(stash, ft_substr(buffer, BUFF_SIZE + 2, (ft_strlen(buffer) - (BUFF_SIZE + 2))));
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
		buffer_bis[bytes_read + 1] = '\0';
		i = 0;
		if (stash_for_next_line != NULL)
		{
			joined_buffer = ft_strjoin((char *)stash_for_next_line, (char *)buffer_bis);
			new_buffer = ft_substr(joined_buffer, 0, BUFF_SIZE + 1); // pq [i] est un de mois que i
			if ((BUFF_SIZE + 2) < ft_strlen(joined_buffer))
				new_stash = ft_substr(joined_buffer, (BUFF_SIZE + 2), (ft_strlen(joined_buffer) - (BUFF_SIZE + 2)));
			else
				new_stash = NULL;
			if (ft_strchr(new_buffer, '\n') != NULL)
				stash_for_next_line = is_new_line(new_buffer, new_stash); // ca va imprimer cut_buffer aussi
			else // no new line
				stash_for_next_line = no_new_line(new_buffer, new_stash); // ca va imprimer cut_buffer aussi
		}
		else
		{
			if (ft_strchr(buffer_bis, '\n') != NULL)
			{
				i = 0;
				while(buffer_bis[i] != '\n')
					i++;
				cut_buffer = ft_substr(buffer, 0, i);
				ft_putstr(cut_buffer);
				stash_for_next_line = ft_substr(buffer_bis, i + 1, (ft_strlen(buffer_bis) - (i + 1)));
			}
			else
				ft_putstr(buffer_bis);

		}

		printf("\nnb_of_bytes dans buffer : %li\n", ft_strlen(buffer));
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
