/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:04:42 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/06 18:33:17 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fdf.h"

static int	x_convert(const char *str)
{
	size_t	num;
	int		i;

	num = 0;
	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f'))
	{
		num = num * 16;
		if (str[i] >= '0' && str[i] <= '9')
			num = num + str[i] - '0';
		else
			num = num + str[i] - 'a' + 10;
		if (num > UINT32_MAX)
			return (0);
		i++;
	}
	return (num);
}

static int	capx_convert(const char *str)
{
	size_t	num;
	int		i;

	num = 0;
	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] >= ('A' && str[i] <= 'F'))
	{
		num = num * 16;
		if (str[i] >= '0' && str[i] <= '9')
			num = num + str[i] - '0';
		else
			num = num + str[i] - 'A' + 10;
		if (num > UINT32_MAX)
			return (0);
		i++;
	}
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
	if (str[i] == '0' && str[i + 1] == 'X')
		return (capx_convert(str + 2 + i));
	return (0);
}
