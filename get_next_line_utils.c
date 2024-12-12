/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:06:41 by camerico          #+#    #+#             */
/*   Updated: 2024/12/12 14:41:15 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen (const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

// si la nouvelle ligne est deja remplie , strjoin s1(line) et s2(buffer)
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*s3;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!s3)
		return (NULL);
	while (s1[i] && (i == 0 || s1[i - 1] != '\n'))
		s3[k++] = s1[i++];
	while (s2[j])
		s3[k++] = s2[j++];
	s3[k] = '\0';
	// free(s1);
	return (s3);
}

// retourne un pointeur vers une nouvelle string copie de *s
// utilise quand la nvlle lign est vide, supplique buffer dans line
// utilise quand stash est remplie(cntenu apres \n),duplique stash dans line
// deja free dans la fonction
char	*ft_strdup_free(const char *s)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	dest = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	free(s);
	return (dest);
}

// recherche la premiere occurence du char c dans *s
// retourne le reste de la string a partir du premier char c trouve (\n)
// verifie s'il y a un \n dan le buffer
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i]) 
	{
		if (s[i] == (char)c)
			return (char *)(s + i);
		i++;
	}
	return (NULL);
}

// retourne une nouvelle string issue de s qui commence a start et
// de taille max len.  s2 est la nouvelle chaine
// utilisation de *malloc*
char	*ft_substr(char const *s, unsigned int start, int len)
{
	int	i;
	int	j;
	char	*s2;

	i = ft_strlen(s);
	j = 0;
	if (!s)
		return (NULL);
	if (start >= i)
		return (ft_strdup(""));
	if (len > i - start)
		len = i - start;
	s2 = malloc(sizeof(char) * len + 1);
	if (!s2)
		return (NULL);
	while (s[start] && j < len)
	{
		s2[j] = s[start];
		j++;
		start++;
	}
	s2[j] = '\0';
	return (s2);
}