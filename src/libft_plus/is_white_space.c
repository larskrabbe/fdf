/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_white_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:23:33 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/04 10:46:25 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"count_stuff.h"

int	is_white_space(int a)
{
	if (a == ' ' || a == '\n' || a == '\t')
		return (1);
	return (0);
}

int	ft_abs(int num)
{
	if (num == -2147483648 || num > 0)
		return (num);
	return(num * -1);
}