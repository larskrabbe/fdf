/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:04:42 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/28 16:08:02 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

static int	x_convert(const char *str)
{
	size_t	num;
	int		i;

	num = 0;
	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') \
	|| (str[i] >= 'A' && str[i] <= 'F'))
	{
		num = num * 16;
		if (str[i] >= '0' && str[i] <= '9')
			num = num + str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			num = num + str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			num = num + str[i] - 'A' + 10;
		if (num > UINT32_MAX)
			return (0);
		i++;
	}
	if (i < 7)
		num = num << 8 | 0xff;
	return (num);
}

int	my_hextoi(const char	*str)
{
	int		i;

	i = 0;
	while (is_white_space(str[i]))
		i++;
	if (str[i] == '0' && str[i + 1] == 'x')
		return (x_convert(str + 2 + i));
	return (0);
}
