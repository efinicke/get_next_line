/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:29:49 by efinicke          #+#    #+#             */
/*   Updated: 2020/10/28 15:26:42 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"

int		main(int argc, char **argv)
{
	int		i;
	char	*line;
	int		fd;
	int		gnl_return;

	line = NULL;
	i = 1;
	if (argc == 1)
	{
		printf("\n-----------------------------------------------------------------\nArgument not found. Please enter a filename or write to the stdin\n-----------------------------------------------------------------\n");
		fd = 0;
	}
	if (argc > 2)
	{
		printf("\n-------------------------------------\nOnly one argument needs to be entered\n-------------------------------------\n");
		return (1);
	}
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("\n---------------------------\nError : unable to open file\n---------------------------\n");
			return (1);
		}
	}
	{
		while ((gnl_return = get_next_line(fd, &line)) > 0)
		{
			printf("gnl_return line %d: %d [%s]\n", i++, gnl_return, line);
			//getchar();
			free(line);
		}
		printf("gnl_return line %d: %d [%s]\n", i++, gnl_return, line);
		free(line);
		gnl_return = get_next_line(fd, &line);
	}
	if (close(fd) == -1)
	{
		printf("\n------------------\nFile closing error\n-----------------\n");
		return (1);
	}
	printf("\nTest des leaks\n");
	system("leaks a.out | grep leaked\n");
	return (0);
}
