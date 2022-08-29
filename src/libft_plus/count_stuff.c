/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:48:02 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/08/29 15:40:21 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*----------------------------------------------------------------------------*\
|																			   |
|		Will later be transform into  a sub libary for libft				   |
|																			   |
\*----------------------------------------------------------------------------*/

#include	"count_stuff.h"

//counts the how many times charackter chr apears in a str and returns the value as a int
//returns 0 if str == null and 1 if chr is '\0'
int	count_chr_from_str(const char *str, const char chr)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	if(str == NULL)
		return(0);
	if(chr == '\0')
		return(1);
	while(str[i] != '\0')
	{
		if(str[i] == chr)
			n++;
		i++;
	}
	return(n);
}

// counts the amount of lines of a file and returns the amount as a int
// could be easily transform to count for any chareckters not just '\n'
int	counts_lines_from_file(char *file)
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1] ;
	int		lines;

	lines = 0;
	fd = open(file,O_RDONLY);
	while(read(fd,buffer,BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		lines = lines + count_chr_from_str(buffer,'\n');
	}
	close(fd);
	return(lines);
}

//coutns the amount of words the amount of 'words' in a string split by char split ( like space) 
// returns the amount as int 
int	count_words_in_str(char *str)
{
	int	i;
	int n;

	i = 0;
	n = 0;
	while(str[i] != '\0')
	{
		while (is_white_space(str[i]))
		{
			i++;
		}
		if(!(is_white_space(str[i])) && str[i] != '\0')
		{
			n++;
			while (!is_white_space(str[i]))
			{
				i++;
			}
		}
	}
	return(n);
}
