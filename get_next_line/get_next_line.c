/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina <carolina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:13:43 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/06 11:56:24 by carolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFF_SIZE 20

static char	*is_new_line(char *buffer, char info)
{
    size_t	i;
    char	*cut_buffer;
    char	*stash_for_next_line;

    if (info == 'y')
    {
        i = 0;
        while(buffer[i] != '\n') // ou utiliser strchr?
            i++; //lenght jusqu'au \n
        i+=1; // car [i] est un de mois que i
    }
    else
        i = BUFF_SIZE;
    if (i < ft_strlen(buffer))
        stash_for_next_line = ft_substr(buffer, i, (ft_strlen(buffer) - i));
    else
        stash_for_next_line = NULL;
    cut_buffer = ft_substr(buffer, 0, i);
    ft_putstr(cut_buffer);
    return (stash_for_next_line);
}

static char	*is_new_line_endofbuffer(char *stash, char info)
{
	size_t	i;
	char	*stash_to_print;
    char	*stash_for_next_line;

    if (info == 'y')
    {
        i = 0;
        while(stash[i] != '\n') // ou utiliser strchr?
            i++; //lenght jusqu'au \n
        i+=1; // car [i] est un de mois que i
    }
    else
        i = BUFF_SIZE;
    if (i < ft_strlen(stash))
        stash_for_next_line = ft_substr(stash, i, (ft_strlen(stash) - i));
    else
        stash_for_next_line = NULL;
    stash_to_print = ft_substr(stash, 0, i);
    ft_putstr(stash_to_print);
    return (stash_for_next_line);
}

char	*get_next_line(int fd) // verifier si bon prototype
{
	int	bytes_read;
	char	buffer[BUFF_SIZE + 1];
	char	*joined_buffer;
	char	*stash_for_next_line;
	char	*type_of_buffer;

	bytes_read = read(fd, buffer, BUFF_SIZE);
	if (bytes_read > 0)
	{
		if (stash_for_next_line != NULL)
		{
			joined_buffer = ft_strjoin((char *)stash_for_next_line, (char *)buffer);
			type_of_buffer = joined_buffer;
			printf("\njoined buffer : %s\n", joined_buffer);
		}
		else
			type_of_buffer = buffer;
		printf("\nbuffer affiché : \n");
		if (ft_strchr(type_of_buffer, '\n') != NULL) // ca va imprimer cut_buffer aussi
			stash_for_next_line = is_new_line(type_of_buffer, 'y'); // couper jusqu a \n
		else // no new line
			stash_for_next_line = is_new_line(type_of_buffer, 'n'); // couper jusqu a buff_size
		printf("\nstash : %s\n", stash_for_next_line);
	}
	else
	{
		if (stash_for_next_line == NULL) //while stash != null on continue de couper à chaque \n
			return ("");
		else
		{
			printf("\nstash affiché : \n");
			if (ft_strchr(stash_for_next_line, '\n') != NULL) // ca va imprimer cut_buffer aussi
				stash_for_next_line = is_new_line_endofbuffer(stash_for_next_line, 'y'); // couper jusqu a \n
			else // no new line
				stash_for_next_line = is_new_line_endofbuffer(stash_for_next_line, 'n'); // couper jusqu a buff_size
			printf("\nstash : %s\n", stash_for_next_line);
		}
	}
}
