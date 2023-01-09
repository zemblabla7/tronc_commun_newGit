/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina <carolina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:13:43 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/09 14:32:49 by carolina         ###   ########.fr       */
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
	//char	buffer[BUFF_SIZE + 1];
	char	*buffer;
	static char	*in_memory;
	char	*new_buffer;
	char	*to_print;
	static bool isFirstCall = true; //norminette verfifier

	if (isFirstCall)
	{
		in_memory = NULL;
		to_print = NULL;
		new_buffer = NULL;
		isFirstCall = false;
		//bytes_read = 0;
		buffer = malloc((BUFF_SIZE + 1) * sizeof(char));
	}
	bytes_read = read(fd, buffer, BUFF_SIZE);
	if (bytes_read > 0)
	{
		if (in_memory != NULL)
			new_buffer = ft_strjoin((char *)in_memory, (char *)buffer); //joined_buffer
		else
			new_buffer = buffer;
		if (ft_strchr(new_buffer, '\n') != NULL) // ca va imprimer cut_buffer aussi
		{
			to_print = is_new_line(new_buffer, '\n', 'p'); // couper jusqu a \n
			in_memory = is_new_line(new_buffer, '\n', 'm');
		}
		else // no new line
		{
			to_print = is_new_line(new_buffer, '\0', 'p'); // couper jusqu a buff_size
			in_memory = is_new_line(new_buffer, '\0', 'm');
		}
	}
	else
	{
		//free(new_buffer); // ça me rajoute des erreurs
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
	//free(new_buffer);
	//free(buffer);
	// if (ft_strchr(to_print, '\0') != NULL)
	// 	free(in_memory);
	// if (to_print[ft_strlen(to_print) + 1] == '\0') // le pb est qu'il y a tjrs un \0 car ft_substr les met
	// 	free(in_memory);
	return (to_print);
}
