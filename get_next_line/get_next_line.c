/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:13:43 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/07 14:16:23 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFF_SIZE 10

static char	*is_new_line(char *big, char info) //le pb vient de big
{
    size_t	i;
    char	*to_print;
    char	*in_memory;

	i = 0;
	while(big[i] != info && i < BUFF_SIZE)
		i++; //lenght jusqu'au \n, \0 ou BUFF_SIZE
	i+=1; // car [i] est un de mois que i
    if (i < ft_strlen(big))
		in_memory = ft_substr(big, i, (ft_strlen(big) - i));
    else
		in_memory = NULL;
    to_print = ft_substr(big, 0, i);
    ft_putstr(to_print);
    return (in_memory);
}

void	get_next_line(int fd) // verifier si bon prototype
{
	int	bytes_read;
	char	buffer[BUFF_SIZE + 1];
	char	*joined_buffer;
	char	*stash;
	char	*type_of_buffer;

	bytes_read = read(fd, buffer, BUFF_SIZE);

	static bool s_isFirstCall = true;

	if (s_isFirstCall)
	{
		stash = NULL;
		s_isFirstCall = false;
	}

	if (bytes_read > 0)
	{
		if (stash != NULL)
		{
			joined_buffer = ft_strjoin((char *)stash, (char *)buffer);
			type_of_buffer = joined_buffer;
		}
		else
			type_of_buffer = buffer;
		if (ft_strchr(type_of_buffer, '\n') != NULL) // ca va imprimer cut_buffer aussi
			stash = is_new_line(type_of_buffer, '\n'); // couper jusqu a \n
		else // no new line
			stash = is_new_line(type_of_buffer, '\0'); // couper jusqu a buff_size
	}
	else
	{
		if (stash == NULL) //while stash != null on continue de couper à chaque \n
			ft_putstr("");
		else
		{
			if (ft_strchr(stash, '\n') != NULL) // ca va imprimer cut_buffer aussi
				stash = is_new_line(stash, '\n'); // couper jusqu a \n
			else // no new line
				stash = is_new_line(stash, '\0'); // couper jusqu a buff_size
		}
	}
}
