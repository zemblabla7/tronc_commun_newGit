/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:02:23 by carolina          #+#    #+#             */
/*   Updated: 2023/01/07 13:47:46 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

void    get_next_line(int fd);
//static char    *is_new_line(char *buffer, char info); // comme static pas besoin de la mettre ici? en tt cas tripouille me dit erreur sinon
char    *ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
