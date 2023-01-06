/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_static.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina <carolina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:13:43 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/06 11:34:02 by carolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFF_SIZE 15

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
		}
		else
			type_of_buffer = buffer;
		
		if (ft_strchr(type_of_buffer, '\n') != NULL) // ca va imprimer cut_buffer aussi
			stash_for_next_line = is_new_line(type_of_buffer, 'y'); // couper jusqu a \n
		else // no new line
			stash_for_next_line = is_new_line(type_of_buffer, 'n'); // couper jusqu a buff_size
	}
	if (bytes_read == 0 && stash_for_next_line != NULL)
		return(stash_for_next_line);
}
