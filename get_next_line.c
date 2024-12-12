/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:25:30 by camerico          #+#    #+#             */
/*   Updated: 2024/12/12 18:32:32 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup_free(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, int len);

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*stash;
	char	*line;
	char *newline;

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
			return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_to_buffer_to_line(fd, buffer, line);
	newline = ft_separate_line(line, stash);
	stash = stash_for_new_line(line);
	return (newline);
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
		if (ft_strchr(buffer, '\n') != NULL) // s'il trouve un \n, sort de la boucle 
			b_read = 0;
		if (line != NULL && line == '\0')
			line = ft_strdup_free(buffer);
		else
			line = ft_strjoin(line, buffer);
			free(buffer);
	}
	return (line);
}

// prend la line et la decoupe. Retourne la line jusqu'au \n
char	*ft_separate_line(char *line, char *stash)
{
	char	*newline;
	int	i;
	char	*tmp;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		newline = ft_substr(line, 0, i + 1);
	else
		newline = ft_strdup(line);
	if (!newline)
		return (NULL);
	if (stash != NULL)
	{
		tmp = ft_strjoin(stash, newline);
		if (!tmp)
			return (NULL);
		free(newline);
		newline = tmp;
	}
	return (newline);
}

// donne a la stash ce qu'il y a apres le /n
char	*stash_for_new_line(char *line)
{
	int	i;
	int	len;
	char	*stash;

	i = 0;
	len = ft_strlen(line);
	while(line[i] && line[i] != '\n')
		i++;
	if (i == len && line[i] != '\n')
		return (0);
	stash = ft_substr(line, i + 1, len);
	return (stash);
}


