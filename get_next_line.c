/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:06:18 by camerico          #+#    #+#             */
/*   Updated: 2024/12/09 18:08:04 by camerico         ###   ########.fr       */
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
	line = manage_stash_and_line(&stash, buffer); // Gerer stash + extraire ligne
	free(buffer);
	return (line);
}

// pour lire le fichier associe a fd et remplir le buffer
// avec n (BUFFER_SIZE) charact.
char	*read_to_buffer(int fd, char *buffer)
{
	ssize_t	b_read;

	b_read = read(fd, buffer, BUFFER_SIZE);
	if (b_read == -1)
		return (NULL);
	while (b_read > 0)
		buffer[b_read] = '\0';
	return (buffer);
}

// si stash vide, copier tout le buffer dans stash
// si stash deja rempli, ajouter le coontenu de buffer dns stash
// puis vider le buffer

// cherche le 1er \n ou \0. si trouve copie jusqu'a \n dans line 
// en gardant le contenu restant ninon return NULL et continuer a lire
char	*manage_stash_and_line(char *stash, char *buffer)
{
	char *line;
	char *tmp;
	int	i;

	i = 0;
	if (stash =! NULL)
		line = ft_strdup_free(stash);
	while (buffer[i] || buffer[i] != '\n')
		i++;
	if (buffer[i] != '\n')
	{
		if (line == NULL)	
		line = ft_strjoin_free(buffer)
	}
	else
	{
		line = ft_strchr(buffer, '\n');
		stash = 
	}
	
	else if (line == NULL)
		line = ft_strjoi(buffer);
	else
		line = ft_strjoin_free
	
}
