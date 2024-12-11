/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:25:30 by camerico          #+#    #+#             */
/*   Updated: 2024/12/11 13:55:28 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
char	*ft_strdup_free(const char *s);
char	*ft_strchr(const char *s, int c);

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*stash;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
			return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = 
	buffer = 
	return (line);
}

// lit avec read le fichier, et ft_strjoin le buffer a line
// tant qu'il n'y a pas de \n
char	*read_to_buffer_to_line(int fd, char *buffer, char line)
{
	ssize_t	b_read;

	b_read = 1;
	while(b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (NULL);
		if (ft_strchr(buffer, '\n') != NULL) // s'il en trouve, il va retourner ce au'il y a apres
			b_read = 0;
		if (line != NULL && line[0] == '\0')
			line = ft_strdup_free(buffer);
		else
			line = ft_strjoin_free(line, buffer);
	}
	free(buffer);
	return (line);
}

// prend la line et la decoupe. Retourne la line jusqu'au \n
char	ft_separate_line(char *line, char *stash)
{
	char	*newline;
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	newline = ft_substr(line, 0, i);
	if (stash != '\0')
		ft_strjoin_free(stash, newline);
	return (newline);
}
