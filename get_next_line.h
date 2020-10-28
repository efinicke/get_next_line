/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 14:01:59 by efinicke          #+#    #+#             */
/*   Updated: 2020/10/25 18:20:13 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		get_next_line(const int fd, char **line);
char	*backslash_n(char *bigstring, int c);
char	*rest_after_backslash_n(char *bigstring, char **line, char *c);
char	*end_of_file(char *bigstring, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin_free(char const *s1, char const *s2);

#endif
