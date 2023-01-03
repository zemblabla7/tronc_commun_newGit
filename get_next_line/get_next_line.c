/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina <carolina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:13:43 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/03 15:45:45 by carolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *buffer;
	int nb_of_bits;
	int ret;

	nb_of_bits = 10;
	buffer = ft_calloc(nb_of_bits + 1, sizeof(char));
	//buffer[nb_of_bits + 1] = '\0';
	while(ret = read(fd, buffer, nb_of_bits));
	{
		buffer[ret] = '\0';
		ft_putnbr(ret);
		ft_putstr(buffer);
	}
	ft_putnbr(ret);
	//printf("%s", buffer);

}

int main ()
{
	int fd = open("test", O_RDONLY | O_CREAT);

	printf("%s", get_next_line(fd));

	close(fd);
	return 0;
}
