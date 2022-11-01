/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:48:02 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/01 21:13:51 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft_plus.h"

int	count_chr_from_str(const char *str, const char chr)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	if (str == NULL)
		return (0);
	if (chr == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			n++;
		i++;
	}
	return (n);
}

int	counts_lines_from_file(char *file)
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	int		lines;

	lines = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (-1);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		lines = lines + count_chr_from_str(buffer, '\n');
		ft_bzero(buffer, BUFFER_SIZE * sizeof(char));
	}
	close(fd);
	return (lines);
}

int	count_words_in_str(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		while (is_white_space(str[i]))
		{
			i++;
		}
		if (!(is_white_space(str[i])) && str[i] != '\0')
		{
			n++;
			while (!is_white_space(str[i]))
			{
				i++;
			}
		}
	}
	return (n);
}
