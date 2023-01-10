/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina <carolina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:02:15 by carolina          #+#    #+#             */
/*   Updated: 2023/01/09 15:44:35 by carolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main ()
{
	int fd;
	int	i;
	char *line;

	fd = open("test2", O_RDONLY | O_CREAT); // remplacer "test" par av[1] par exemple
	if (fd == -1)
	{
		ft_putstr("open command failed\n");
		return (1);
	}

	i = 0;
	while (i < 8)
	{
		line = get_next_line(fd);
		printf("%s", line);
		//printf("\n");
		free(line);
		i++;
	}
	//free();

	if (close(fd) == -1) // en checkant si = -1, ça execute la commande "close"
	{
		ft_putstr("close command failed\n");
		return (1);
	}

	return 0;
}

//FAIRE LES BONUS
