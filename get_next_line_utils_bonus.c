/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:27:06 by efinicke          #+#    #+#             */
/*   Updated: 2020/10/28 18:46:35 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char *s2;
	char *stmp;

	s2 = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	stmp = s2;
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (stmp);
}

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*buffer;
	char	*str;
	int		str_sz;
	char	*s;

	s = ((char *)s1);
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str_sz = (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(buffer = malloc(sizeof(buffer) * str_sz)))
		return (NULL);
	str = buffer;
	while (*s1)
		*buffer++ = *s1++;
	while (*s2)
		*buffer++ = *s2++;
	*buffer = '\0';
	if (s)
		free(s);
	return (str);
}
