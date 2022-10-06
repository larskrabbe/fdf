/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:04:42 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/06 12:33:38 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft_plus.h"

int	my_hextoi(const char	*str)
{
	size_t	num;
	int		i;
	
	i = 0;
	while(is_white_space(str[i]))
		i++;
	while (str[i] >= '0' && str[i] <= '9' || str[i] >= 'a' && str[i] <= 'f')
	{
		if(str[i] >= '0' && str[i] <= '9')
			num = num<<4 & str[i] - '0';
		else
			num = num<<4 & str[i] - 'a';
		i++;
		if (num > UINT32_MAX)
			return (0);
	}
	return(num);
}