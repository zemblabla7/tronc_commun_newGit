/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:13:43 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/07 18:55:17 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFF_SIZE 4

static char	*is_new_line(char *big, char info, char variable) //le pb vient de big
{
    size_t	i;
    char	*to_print;
    char	*in_memory;

	i = 0;
	while(big[i] != info)
		i++; //lenght jusqu'au \n, \0 ou BUFF_SIZE
	i+=1; // car [i] est un de mois que i
	if (i < ft_strlen(big))
		in_memory = ft_substr(big, i, (ft_strlen(big) - i));
	else
		in_memory = NULL;
	to_print = ft_substr(big, 0, i);
	if (variable == 'm') //memory
	{
		free(to_print);
		return(in_memory);
	}
	else /*if (variable == 'p')*/ //print
		return(to_print);
}

char	*get_next_line(int fd) // verifier si bon prototype
{
	int	bytes_read;
	char	buffer[BUFF_SIZE + 1];
	static char	*in_memory;
	char	*type_of_buffer;
	char	*to_print;
	static bool isFirstCall = true; //norminette verfifier

	if (isFirstCall)
	{
		in_memory = NULL;
		to_print = NULL;
		type_of_buffer = NULL;
		isFirstCall = false;
	}
	bytes_read = read(fd, buffer, BUFF_SIZE);
	if (bytes_read > 0)
	{
		if (in_memory != NULL)
			type_of_buffer = ft_strjoin((char *)in_memory, (char *)buffer); //joined_buffer
		else
			type_of_buffer = buffer;
		if (ft_strchr(type_of_buffer, '\n') != NULL) // ca va imprimer cut_buffer aussi
		{
			to_print = is_new_line(type_of_buffer, '\n', 'p'); // couper jusqu a \n
			in_memory = is_new_line(type_of_buffer, '\n', 'm');
		}
		else // no new line
		{
			to_print = is_new_line(type_of_buffer, '\0', 'p'); // couper jusqu a buff_size
			in_memory = is_new_line(type_of_buffer, '\0', 'm');
		}
	}
	else
	{
		free(type_of_buffer);
		if (in_memory == NULL) //while in_memory != null on continue de couper à chaque \n
		{
			free(in_memory); // ne change rien au nb de free sur valgrind
			return ("");
		}
		else
		{
			if (ft_strchr(in_memory, '\n') != NULL) // ca va imprimer cut_buffer aussi
			{
				to_print = is_new_line(in_memory, '\n', 'p'); // couper jusqu a \n
				in_memory = is_new_line(in_memory, '\n', 'm');
			}
			else // no new line
			{
				to_print = is_new_line(in_memory, '\0', 'p'); // couper jusqu a buff_size
				in_memory = is_new_line(in_memory, '\0', 'm');
			}
		}
	}
	// if (ft_strchr(to_print, '\0') != NULL)
	// 	free(in_memory);
	// if (to_print[ft_strlen(to_print) + 1] == '\0') // le pb est qu'il y a tjrs un \0 car ft_substr les met
	// 	free(in_memory);
	return (to_print);
}
