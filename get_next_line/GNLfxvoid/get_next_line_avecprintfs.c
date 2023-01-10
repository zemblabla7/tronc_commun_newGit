/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina <carolina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:13:43 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/06 16:28:49 by carolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFF_SIZE 10

static char	*is_new_line(char *big, char info) //le pb vient de big
{
    size_t	i;
    char	*to_print;
    char	*in_memory;

	//printf("\nnb_of_bytes dans big : (%li)\n", ft_strlen(big));
	//printf("\nbig : %s (%li)\n", big, ft_strlen(big));
	i = 0;
	while(big[i] != info && i < BUFF_SIZE)
	{
		//printf("\nBIG[I] : %c\n", big[i]);
		i++; //lenght jusqu'au \n, \0 ou BUFF_SIZE
	}
	i+=1; // car [i] est un de mois que i
	// if (big[i] == '\0')
	// 	printf("FIN2");
    if (i < ft_strlen(big))
		in_memory = ft_substr(big, i, (ft_strlen(big) - i));
    else
		in_memory = NULL;
	// if (in_memory != NULL)
	// {
	// 	printf("\nnb_of_bytes dans in_memory : %s (%li)\n\n", in_memory, ft_strlen(in_memory));
	// }
    to_print = ft_substr(big, 0, i);
    ft_putstr(to_print);
	// printf("\nnb_of_bytes dans to_print : (%li)\n", ft_strlen(to_print));
	// printf("\ni : (%li)\n", i);
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
	//buffer[ft_strlen(buffer) + 1] = '\0';
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
		//printf("\nplus de bytes_read\n");
		if (stash == NULL) //while stash != null on continue de couper à chaque \n
			ft_putstr("");
		else
		{
			//printf("\nstash : %s\n\n", stash);
			if (ft_strchr(stash, '\n') != NULL) // ca va imprimer cut_buffer aussi
				stash = is_new_line(stash, '\n'); // couper jusqu a \n
			else // no new line
				stash = is_new_line(stash, '\0'); // couper jusqu a buff_size
		}
	}
	// printf("\nnb of bytes read (%i)\n", bytes_read);
	// printf("\nnb_of_bytes dans buffer : (%li)\n", ft_strlen(buffer));
	// if (stash != NULL)
	// 	printf("\nnb_of_bytes dans stash : (%li)\n\n", ft_strlen(stash));
}