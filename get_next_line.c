/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:06:18 by camerico          #+#    #+#             */
/*   Updated: 2024/12/05 19:17:01 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*stash;
	char	*line;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		{
			free(buffer);
			return (NULL);
		}
	stash = 

}

// pour lire le fichier et remplir le buffer avec n (BUFFER_SIZE) charact.
static char	*read_to_buffer(int	fd, static char *stash, char *buffer)
{
	
}

// stash est une variable static
// si stash vide, copier tout le buffer dans stash
// si stash deja rempli, ajouter le coontenu de buffer dns stash
// puis vider le buffer
char	*manage_stash
{
	
}

// cherche le 1er \n ou \0. si trouve copie jusqu'a \n dans line 
// en gardant le contenu restant ninon return NULL et continuer a lire
char	*etract_line