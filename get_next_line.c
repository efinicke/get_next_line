/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:18:40 by efinicke          #+#    #+#             */
/*   Updated: 2020/10/27 19:25:47 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*backslash_n(char *bigstring, int c)
{
	int	i;

	i = 0;
	while (bigstring[i] && bigstring[i] != c)
		i++;
	if (bigstring[i] == c)
		return (&bigstring[i]);
	else
		return (NULL);
}

char	*rest_after_backslash_n(char *bigstring, char **line, char *c)
{
	char	*tmp;

	*c = '\0';
	*line = ft_strdup(bigstring);
	tmp = ft_strdup(c + 1);
	free(bigstring);
	bigstring = NULL;
	bigstring = tmp;
	return (bigstring);
}

char	*end_of_file(char *bigstring, char **line)
{
	*line = ft_strdup(bigstring);
	free(bigstring);
	bigstring = NULL;
	return (bigstring);
}

int		get_next_line(int fd, char **line)
{
	static char		*bigstring = NULL;
	char			*c;
	char			buf[BUFFER_SIZE + 1];
	int				read_ret;
	int				i;

	c = NULL;
	if (fd < 0 || !line || BUFFER_SIZE < 0)
		return (-1);
	while ((read_ret = read(fd, buf, BUFFER_SIZE)) > 0 || i != -1)
	{
		buf[read_ret] = '\0';
		bigstring = ft_strjoin_free(bigstring, buf);
		if ((c = backslash_n(bigstring, '\n')) == NULL)
			i = -1;
		if (c != NULL)
		{
			bigstring = rest_after_backslash_n(bigstring, line, c);
			return (1);
		}
	}
	bigstring = end_of_file(bigstring, line);
	if (read_ret == 0)
		return (0);
	return (-1);
}
